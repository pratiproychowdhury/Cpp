#include <bits/stdc++.h>

using namespace std;

class IceCream {
    
    public: 
        int flavor; 
        int index;

        IceCream(int flavor, int index) {
            this->flavor = flavor;
            this->index = index;
       }
};
    

bool compare (IceCream a, IceCream b) {
    
    return (a.flavor < b.flavor);
}
    
    
int binarySearch(int first, int last, vector<IceCream> arr, int search) {
   
    if (first > last)
        return -1;
    
    if (search == arr[first].flavor)
        return arr[first].index;
    
    if (search < arr[(first+last)/2].flavor)
        return binarySearch(first, ((first+last)/2)-1, arr, search);
    
    if (search > arr[(first+last)/2].flavor)
        return binarySearch(((first+last)/2)+1, last, arr, search);
    
    if (search == arr[(first+last)/2].flavor) {
        //cout << "found value " << search  << " in index " << (first+last)/2 << endl;
        return arr[(first+last)/2].index;
    }
    else return -1;
}


int main() {
    int t;
    int n, m; // m is money, n is num of icecream
    cin >> t;
    for(int test = 0; test < t; test++) {       
        cin >> m >> n;
        vector<IceCream> arr;
        arr.reserve(n); 

        for (int i = 0; i < n; i++) {
            int cost;
            cin >> cost;
            arr.push_back(IceCream(cost, i + 1));
        }

        sort(arr.begin(), arr.end(), compare);
        
        //for (int i = 0; i < n; i++)
        //    cout << "ice: " << arr[i].index << " " << arr[i].flavor << "\n";
        
        int firstIndex = 100000, secondIndex = 100000;
        for(int i = 0; i < n - 1 ; i++) {
            int search = m - arr[i].flavor;
            if(search >= arr[i].flavor) {
                int index = binarySearch( i + 1, n - 1, arr, search);
                if( index != -1 ) {
                    cout << min(arr[i].index, index) << " " << max(arr[i].index, index) << endl;
                    break;
                }
            }
        } // end of sort
    }
}
