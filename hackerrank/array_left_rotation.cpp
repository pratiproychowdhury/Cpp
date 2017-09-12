#include <vector>

#include <iostream>

using namespace std;

vector<int> array_left_rotation(vector<int> a, int n, int k) {
    
    int temp;
    int keffective = k % n;
    vector<int> rotated(n);
    

    
    for (int i=0; i<n; i++) {
        rotated[i] = a[(i+keffective) % n];
    }
    
    /*
    for (int rot=0; rot<k; rot++){
        temp = a[0];
        for (int i=1; i<n; i++)
            a[i-1] = a[i];
        a[n-1] = temp;
    }
    */
    
    return rotated;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotation(a, n, k);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}
