#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <iostream>

using namespace std;

int davis (int n) {
    
    static vector<int> alternatives(37, 0);
    
    alternatives[1] = 1;
    alternatives[2] = 2;
    alternatives[3] = 4;
    
    if (alternatives[n] > 0)
        return alternatives[n];
        
    int total = davis(n-3);
    total += davis(n-2);
    total += davis(n-1);
    
    alternatives[n] = total;
    return total;
}

int main(){
    int s;
    cin >> s;
    for(int a0 = 0; a0 < s; a0++){
        int n;
        cin >> n;
        cout << davis(n) << "\n";
    }
    return 0;
}
