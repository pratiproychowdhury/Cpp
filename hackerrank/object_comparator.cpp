#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int score;
}; 

bool compare (Player a, Player b) {
    
    if (a.score < b.score)
        return false;
    if (a.score > b.score)
        return true;
    return (a.name < b.name);
}

vector<Player> comparator(vector<Player> players) {

    sort(players.begin(), players.end(), compare);
    vector<Player> sorted = players;
    return sorted; 
}

int main() {
    
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; i++){
        cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }
    
    vector<Player > answer = comparator(players);
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i].name << " " << answer[i].score << endl;
    }
    return 0;
}
