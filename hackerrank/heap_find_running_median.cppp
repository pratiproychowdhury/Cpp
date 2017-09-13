#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
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
#include <algorithm>
#include <unordered_map>
#include <iomanip>

using namespace std;


int main(){
    int n;
    int nmax = 0;
    int nmin = 0;
    std::priority_queue<int> maxheap;
    std::priority_queue<int, std::vector<int>, std::greater<int> > minheap;
    
    cin >> n;
    vector<int> a(n);
    
    for (int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
        
       if (a_i==0) {
           maxheap.push(a[a_i]);
           nmax++;        
       }
       else if (a[a_i] < maxheap.top()) {
           maxheap.push(a[a_i]);
           nmax++;           
       }
       else {
           minheap.push(a[a_i]);
           nmin++;           
       }
        
       // balance the heaps
       if (nmax<nmin) {
           int x = minheap.top();
           minheap.pop();
           nmin--;
           maxheap.push(x);
           nmax++;
       }
       if (nmin<(nmax-1)) {
           int x = maxheap.top();
           maxheap.pop();
           nmax--;
           minheap.push(x);
           nmin++;
       }       
        
        // cout << "minheap: " << minheap.size() << "nmin " << nmin << "maxheap: " << maxheap.size() << "nmax " << nmax << endl;
        // calculate the median
        double median;
        // cout << "tops " << maxheap.top() << " " << (minheap.empty()?0:minheap.top()) << endl;
        if (minheap.empty())
           median = maxheap.top(); 
        else if ((nmin+nmax)%2)
            median = maxheap.top();
        else median = (maxheap.top()+minheap.top())/2.0;

        cout.precision(5);
        cout << std::fixed << setprecision(1) << median << endl;

        
    }
    return 0;
}
