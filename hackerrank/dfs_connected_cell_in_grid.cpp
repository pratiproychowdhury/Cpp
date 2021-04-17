#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void populate(vector< vector<int> > &grid, int n, int m, int region) {
    
    int x = grid.size();
    int y = grid[0].size();
    
    if ((n>0) && (m>0) && (grid[n-1][m-1] == 1)) {
       grid[n-1][m-1] = region; 
       populate (grid, n-1, m-1, region);
    }
    
    if ((n>0) && (grid[n-1][m] == 1)) {
       grid[n-1][m] = region; 
       populate (grid, n-1, m, region);
    } 

    if ((n>0) && (m<(y-1)) && (grid[n-1][m+1] == 1)) {
       grid[n-1][m+1] = region; 
       populate (grid, n-1, m+1, region);
    }

    if ((m>0) && (grid[n][m-1] == 1)) {
       grid[n][m-1] = region; 
       populate (grid, n, m-1, region);
    }

    if ((m<(y-1)) && (grid[n][m+1] == 1)) {
       grid[n][m+1] = region; 
       populate (grid, n, m+1, region);
    }

    if ((n<(x-1)) && (m>0) && (grid[n+1][m-1] == 1)) {
       grid[n+1][m-1] = region; 
       populate (grid, n+1, m-1, region);
    }

    if ((n<(x-1)) && (grid[n+1][m] == 1)) {
       grid[n+1][m] = region; 
       populate (grid, n+1, m, region);
    }

    if ((n<(x-1)) && (m<(y-1)) && (grid[n+1][m+1] == 1) ){
       grid[n+1][m+1] = region; 
       populate (grid, n+1, m+1, region);
    }
}

int get_biggest_region(vector< vector<int> > grid) {
    
    int largest = 0;
    int region = 2;
    int n = grid.size();
    int m = grid[0].size();
    
    for (int x=0; x<n; x++) {
        for (int y=0; y<m; y++) {
            if (grid[x][y] == 1) {
                grid[x][y] = region;
                populate(grid, x, y, region);
                region++;
            }    
        }
    }

    //for (int x=0; x<n; x++) {
    //    for (int y=0; y<m; y++) {
    //        cout << grid[x][y] << " ";
    //    }
    //    cout << endl;
    //}
    
    for (int i=2; i<= region; i++) {
        int count=0;
        for (int x=0; x<n; x++) {
            for (int y=0; y<m; y++) {
                if (grid[x][y]==i)
                    count++;
            }
        }
        if (count > largest)
            largest = count;
    }
    return largest;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    cout << get_biggest_region(grid) << endl;
    return 0;
}
