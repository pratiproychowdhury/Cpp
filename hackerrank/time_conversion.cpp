/*
Given a time in

-hour AM/PM format, convert it to military (24-hour) time.

Note: Midnight is 12:00:00AM on a 12-hour clock, and 00:00:00 on a 24-hour clock. Noon is 12:00:00PM on a 12-hour clock, and 12:00:00 on a 24-hour clock.

Function Description

Complete the timeConversion function in the editor below. It should return a new string representing the input time in 24 hour format.

timeConversion has the following parameter(s):

    s: a string representing time in 

    hour format

Input Format

A single string
containing a time in -hour clock format (i.e.: or ), where and

.

Constraints

    All input times are valid

Output Format

Convert and print the given time in
-hour format, where

.

Sample Input 0

07:05:45PM

Sample Output 0

19:05:45

*/

#include <bits/stdc++.h>

using namespace std;

string timeConversion(string s) {

    int hour = stoi(s.substr(0,2)) % 12;

    if (s.at(8)=='P')
        hour += 12;

    char strhour[3];
    sprintf(strhour, "%02d", hour);

    return s.replace(0, 2, strhour).substr(0, 8);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
