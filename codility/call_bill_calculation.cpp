#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <sstream>

int solution(string &S) {

    map<string,int> call_durations;
    map<string,int> call_price;
    istringstream input(S);
    string call;
        
    while (getline(input,call)) {
        int hours, minutes, seconds;
        char number[12];

        sscanf(call.c_str(), "%d:%d:%d,%s\n", &hours, &minutes, &seconds, number);
        
        int duration = hours*3600 + minutes*60 + seconds;
        string called_number(number);
        int price;
        if (duration<300)
            price = 3*duration;
        else {
            price = 150*(duration/60);
            if (duration%60)
                price += 150;
        }

        // Include or update the duration and price of calls to this number        
        map<string,int>::iterator duration_ptr = call_durations.find(called_number); 
        if (duration_ptr != call_durations.end())         
            duration_ptr->second += duration;
        else call_durations.emplace(called_number, duration);
            
        map<string,int>::iterator price_ptr = call_price.find(called_number); 
        if (price_ptr != call_price.end())         
            price_ptr->second += price;
        else call_price.emplace(called_number, price);
    }
       
    // Determine the most called number from call_durations and remove it from call_price
    map<string,int>::iterator most_called = call_durations.begin();
    for (map<string,int>::iterator ptr=call_durations.begin(); ptr!=call_durations.end(); ptr++)
        if (ptr->second > most_called->second)
            most_called = ptr;
    
    map<string,int>::iterator to_delete = call_price.find(most_called->first);
    call_price.erase(to_delete);
    
    // Sum up call values
    int total_price = 0;
    for (auto ptr : call_price)
        total_price += ptr.second;

    return total_price;
}
