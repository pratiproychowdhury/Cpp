/*
A cricket match is going to be held. The field is represented by a 1D plane. A cricketer, Mr. X has  favorite shots. Each shot has a particular range. The range of the  shot is from i to i. That means his favorite shot can be anywhere in this range. Each player on the opposite team can field only in a particular range. Player  can field from i to i. You are given the  favorite shots of Mr. X and the range of  players.

 represents the strength of each player i.e. the number of shots player  can stop.
Your task is to find:

.

Game Rules: A player can stop the  shot if the range overlaps with the player's fielding range.

For more clarity about overlapping, study the following figure:

L.png

Input Format

The first line consists of two space separated integers,  and .
Each of the next  lines contains two space separated integers. The  line contains  and .
Each of the next  lines contains two integers. The  line contains integers  and .

Output Format

You need to print the sum of the strengths of all the players: .

Constraints:



Sample Input

4 4                
1 2 
2 3
4 5
6 7
1 5
2 3
4 7
5 7   
Sample Output

9
Explanation

Player 1 can stop the 1st, 2nd and 3rd shot so the strength is .
Player 2 can stop the 1st and 2nd shot so the strength is .
Player 3 can stop the 3rd and 4th shot so the strength is .
Player 4 can stop the 3rd and 4th shot so the strength is .

The sum of the strengths of all the players is .
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int solve(vector<vector<int>> shots, vector<vector<int>> players) {

    multimap<int,int> shotmap;
    for (vector<int> a : shots)
        shotmap.emplace(a[0],a[1]);

    int strength = 0;
    for (vector<int> thisPlayer : players) {
        for (pair<int,int> thisShot : shotmap) {
            if ((thisPlayer[0]<=thisShot.second) && (thisPlayer[1] >= thisShot.first))
                strength++;
            if (thisPlayer[1] < thisShot.first)
                break;
        }
    }
    return strength;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> shots(n);
    for (int shots_row_itr = 0; shots_row_itr < n; shots_row_itr++) {
        shots[shots_row_itr].resize(2);

        for (int shots_column_itr = 0; shots_column_itr < 2; shots_column_itr++) {
            cin >> shots[shots_row_itr][shots_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<vector<int>> players(m);
    for (int players_row_itr = 0; players_row_itr < m; players_row_itr++) {
        players[players_row_itr].resize(2);

        for (int players_column_itr = 0; players_column_itr < 2; players_column_itr++) {
            cin >> players[players_row_itr][players_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = solve(shots, players);

    fout << result << "\n";

    fout.close();

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
