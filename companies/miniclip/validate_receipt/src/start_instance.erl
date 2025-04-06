-module(start_instance).
-export([startit/0]).
-export([send_response/2]).

startit() ->
	ssl:start(),
	inets:start(),
	erlcloud:start(),
	loop().

loop() ->
	Message = erlcloud_sqs:receive_message("receipt_input"),
	[Conteudo | []]  = proplists:get_value(messages, Message),
	Corpo = proplists:get_value(body, Conteudo),

	% Deleting received message from queue
	Receipt_handle = proplists:get_value(receipt_handle, Conteudo),
	erlcloud_sqs:delete_message("receipt_input", Receipt_handle),

	Mapped = jiffy:decode(Corpo, [return_maps]),
	User_Id = maps:get(<<"user_id">>, Mapped),
	Queue =  maps:get(<<"post_queue">>, Mapped),
	Receipt = maps:get(<<"receipt">>, Mapped),
	
	Url_prod = "https://buy.itunes.apple.com/verifyReceipt",
	Url_sandbox = "https://sandbox.itunes.apple.com/verifyReceipt",

	Query = [{<<"receipt-data">>,Receipt}],
	Query_encoded = jsx:encode(Query),
	{ok, {{Version, 200, ReasonPhrase}, Headers, Body}} = httpc:request(post, {Url_prod, [], "application/json", Query_encoded}, [], []),
	Response = jiffy:decode(Body, [return_maps]),
	io:fwrite("Response = ~p~n", [Response]),
	
	case maps:get(<<"status">>, Response) /= 0 of
		true ->
			io:fwrite("Falling back to sandbox test~n"),
			{ok, {{Version_test, 200, ReasonPhrase_test}, Headers_test, Body_test}} = httpc:request(post, {Url_sandbox, [], "application/json", Query_encoded}, [], []),
			Response_test = jiffy:decode(Body_test, [return_maps]),
			io:fwrite("Response_test = ~p~n", [Response_test]),
			Status_code = maps:get(<<"status">>, Response_test, -1),
			Receipt_Check = maps:get(<<"receipt">>, Response_test, -1),
			Transaction_Id = maps:get(<<"transaction_id">>, Receipt_Check, -1);
		false ->
			Status_code = maps:get(<<"status">>, Response, 0),
			Receipt_Check = maps:get(<<"receipt">>, Response, -1),
			Transaction_Id = maps:get(<<"transaction_id">>, Receipt_Check, -1)
	end,

	io:fwrite("Transaction_Id = ~p Status_code = ~p~n", [Transaction_Id, Status_code]),
	
	case Status_code /= 0 of
		true ->
			Status = 'INVALID',
			{ok, []} = erlcloud_ddb2:put_item( <<"ValidatedReceipts">>, [{<<"TransactionId">>, binary_to_integer(Transaction_Id)}]);
		false ->
			Status = 'OK',
			{ok, []} = erlcloud_ddb2:put_item( <<"ValidatedReceipts">>, [{<<"TransactionId">>, binary_to_integer(Transaction_Id)}])
	end,

	Final_result = #{user_id => User_Id, transaction_id => Transaction_Id, status => Status},
	send_response(Queue, Final_result),
	loop().


send_response(Queue, Message) -> erlcloud_sqs:send_message(Queue, jsx:encode(Message)). 

