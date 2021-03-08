/*
Markov takes out his Snakes and Ladders game, stares at the board and wonders: "If I can always roll the die to whatever number I want, what would be the least number of rolls to reach the destination?"

Rules The game is played with a cubic die of  faces numbered  to .

Starting from square , land on square  with the exact roll of the die. If moving the number rolled would place the player beyond square , no move is made.

If a player lands at the base of a ladder, the player must climb the ladder. Ladders go up only.

If a player lands at the mouth of a snake, the player must go down the snake and come out through the tail. Snakes go down only.

Function Description

Complete the quickestWayUp function in the editor below. It should return an integer that represents the minimum number of moves required.

quickestWayUp has the following parameter(s):

ladders: a 2D integer array where each  contains the start and end cell numbers of a ladder
snakes: a 2D integer array where each  contains the start and end cell numbers of a snake
Input Format

The first line contains the number of tests, .

For each testcase:
- The first line contains , the number of ladders.
- Each of the next  lines contains two space-separated integers, the start and end of a ladder.
- The next line contains the integer , the number of snakes.
- Each of the next  lines contains two space-separated integers, the start and end of a snake.

Constraints



The board is always  with squares numbered  to .
Neither square  nor square  will be the starting point of a ladder or snake.
A square will have at most one endpoint from either a snake or a ladder.

Output Format

For each of the t test cases, print the least number of rolls to move from start to finish on a separate line. If there is no solution, print -1.

Sample Input

2
3
32 62
42 68
12 98
7
95 13
97 25
93 37
79 27
75 19
49 47
67 17
4
8 52
6 80
26 42
2 72
9
51 19
39 11
37 29
81 3
59 5
79 23
53 7
43 33
77 21 
Sample Output

3
5
Explanation

For the first test:

The player can roll a  and a  to land at square . There is a ladder to square . A roll of  ends the traverse in  rolls.

For the second test:

The player first rolls  and climbs the ladder to square . Three rolls of  get to square . A final roll of  lands on the target square in  total rolls.
*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class comp {
    pair<int,int> otherval;
    
    public:
        comp(pair<int,int> param): otherval(param) {
        }
        
        bool operator()(pair<int,int> m) {
            return m.first == otherval.first; //or use paramA in some way
        }
};

// Complete the quickestWayUp function below.
int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {

    deque<pair<int,int>> moves;
    set<int> visited;
    
    pair<int,int> initial(1,0);
    moves.push_back(initial);
    visited.emplace(initial.first);
    
    while (!moves.empty()) {
        pair<int,int> position = moves.front();
        moves.pop_front();
        for (int i=1; i<7; i++) {
            pair<int,int> next;
            next.first = position.first+i;
            next.second = position.second+1;
            
            // Ladder and snakes
            for (int a=0; a<ladders.size(); a++)
                if (ladders[a][0] == next.first) {
                    next.first = ladders[a][1];
                }
            for (int a=0; a<snakes.size(); a++)
                if (snakes[a][0] == next.first) {
                    next.first = snakes[a][1];
                }

            //deque<pair<int,int>>::iterator ptr = find_if(moves.begin(), moves.end(), comp(next));
            if (next.first == 100) {
              return next.second;  
            }  
            //else if ( (next.first < 100) && (ptr == moves.end()) ) {
            else if ( (next.first < 100) && (visited.find(next.first) == visited.end()) ) {
                moves.push_back(next);
                visited.emplace(next.first); 
            }
        } 
    }
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> ladders(n);
        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> ladders[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> snakes(m);
        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> snakes[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = quickestWayUp(ladders, snakes);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
