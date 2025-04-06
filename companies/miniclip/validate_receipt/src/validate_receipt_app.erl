%%%-------------------------------------------------------------------
%% @doc validate_receipt public API
%% @end
%%%-------------------------------------------------------------------

-module(validate_receipt_app).

-behaviour(application).

-export([start/2, stop/1]).

start(_StartType, _StartArgs) ->
    validate_receipt_sup:start_link().

stop(_State) ->
    ok.

%% internal functions
