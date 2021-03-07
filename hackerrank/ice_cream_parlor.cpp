/*
Each time Sunny and Johnny take a trip to the Ice Cream Parlor, they pool their money to buy ice cream. On any given day, the parlor offers a line of flavors. Each flavor has a cost associated with it.

Given the value of
and the of each flavor for trips to the Ice Cream Parlor, help Sunny and Johnny choose two distinct flavors such that they spend their entire pool of money during each visit. ID numbers are the 1- based index number associated with a

. For each trip to the parlor, print the ID numbers for the two types of ice cream that Sunny and Johnny purchase as two space-separated integers on a new line. You must print the smaller ID first and the larger ID second.

For example, there are
flavors having . Together they have to spend. They would purchase flavor ID's and for a cost of . Use

based indexing for your response.

Note:

    Two ice creams having unique IDs 

and may have the same cost (i.e.,

    ).
    There will always be a unique solution.

Function Description

Complete the function whatFlavors in the editor below. It must determine the two flavors they will purchase and print them as two space-separated integers on a line.

whatFlavors has the following parameter(s):

    cost: an array of integers representing price for a flavor
    money: an integer representing the amount of money they have to spend

Input Format

The first line contains an integer,

, the number of trips to the ice cream parlor.

Each of the next
sets of

lines is as follows:

    The first line contains 

.
The second line contains an integer,
, the size of the array
.
The third line contains
space-separated integers denoting the

    .

Constraints

Output Format

Print two space-separated integers denoting the respective indices for the two distinct flavors they choose to purchase in ascending order. Recall that each ice cream flavor has a unique ID number in the inclusive range from
to

.

Sample Input

2
4
5
1 4 5 3 2
4
4
2 2 4 3

Sample Output

1 4
1 2

Explanation

Sunny and Johnny make the following two trips to the parlor:

    The first time, they pool together 

dollars. There are five flavors available that day and flavors and have a total cost of
.
The second time, they pool together
dollars. There are four flavors available that day and flavors and have a total cost of .
*/

#include <bits/stdc++.h>
#include <algorithm> 

using namespace std;

vector<string> split_string(string);



void whatFlavors(vector<int> cost, int money) {

    multimap<int, int> flavors;
    for (int i=0; i<cost.size(); i++)
        flavors.emplace(cost[i], i);

    for (pair<int, int> a : flavors) {
        int remaining = money - a.first;
        multimap<int, int>::iterator thisFlavor = flavors.find(remaining);
        if ((thisFlavor != flavors.end()) && (a.second == thisFlavor->second))
            thisFlavor++;
        if (thisFlavor != flavors.end()) {
            if (a.second < thisFlavor->second)
                cout << a.second+1 << " " << thisFlavor->second+1 << endl;
            else
               cout << thisFlavor->second+1 << " " << a.second+1 << endl;
            return; 
        }
    }
}

// THE SECOND SOLUTION; THIS ONE RETURNS A VECTOR WITH THE INDICES OF THE FLAVORS

vector<int> icecreamParlor(int m, vector<int> arr) {

    for (vector<int>::iterator ptr=arr.begin(); ptr!=arr.end(); ptr++) {
        int rest = m - *ptr;
        vector<int>::iterator next = ptr+1;
        vector<int>::iterator theother = find(next, arr.end(), rest);
        if (theother != arr.end()) {
            vector<int> solution = { distance(arr.begin(), ptr)+1, distance(arr.begin(), theother)+1 };
            return solution;
        }

    }
    return vector<int> ();
}






int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int money;
        cin >> money;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split_string(cost_temp_temp);

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
