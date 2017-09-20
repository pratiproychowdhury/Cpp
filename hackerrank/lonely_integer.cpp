#include <cmath>
#include <ctime>
#include <string>
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

using namespace std;

int lonely_integer(vector < int > a) {
    vector <int> b(101, 0);

    for (int x=0; x<a.size(); x++) 
        b[a[x]]++;

        
    for (int x=0; x<101; x++)     
        if (b[x]%2)
            return x;

    return -1;    
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    cout << lonely_integer(a) << endl;
    return 0;
}
