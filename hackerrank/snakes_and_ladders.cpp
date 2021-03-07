#include <queue>

using namespace std;

// Complete the quickestWayUp function below.
int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    queue<pair<int,int>> moves;
    pair<int,int> initial(1,0);

    // Ladder and snake
    for (int a=0; a< max(ladders.size(), snakes.size()); a++) {
        if ((a<ladders.size()) && (ladders[a][0] == initial.first)) {
            initial.first = ladders[a][1];
            a=0;
        }
        if ((a<snakes.size()) && (snakes[a][0] == initial.first)) {
            initial.first = ladders[a][1];
            a=0;
        }                  
    }
    moves.emplace(initial);
        
    while (!moves.empty()) {
        pair<int,int> position = moves.front();
        moves.pop();
        for (int i=1; i<7; i++) {
            pair<int,int> next;
            next.first = position.first++;
            next.second = position.second++;

            // Ladder and snake
            for (int a=0; a< max(ladders.size(), snakes.size()); a++) {
                if ((a<ladders.size()) && (ladders[a][0] == next.first)) {
                    next.first = ladders[a][1];
                    a=0;
                }
                if ((a<snakes.size()) && (snakes[a][0] == next.first)) {
                    next.first = ladders[a][1];
                    a=0;
                }                  
            }
            
            if (next.first == 100)
                return next.second;
            else if (next.first < 100)
                moves.emplace(next);
        } 
    }
    return -1;
}
