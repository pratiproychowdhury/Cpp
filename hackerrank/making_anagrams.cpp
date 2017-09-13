#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int number_needed(string a, string b) {
   
    int changes = 0;
    vector<int> aletters(26);
    vector<int> bletters(26);
    
    for (int i=0; i<a.length(); i++) {
        aletters[a[i]-'a']++;
    }
    for (int i=0; i<b.length(); i++) {
        bletters[b[i]-'a']++;
    }
    
    for (int i=0; i<26; i++) 
        changes += abs(aletters[i]-bletters[i]);
    return changes;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
