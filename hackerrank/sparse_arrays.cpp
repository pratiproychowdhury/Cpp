#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;


int main() {

    int num_words, queries;
    unordered_multiset<string> words;
    
    cin >> num_words;
    
    for (int x=0; x<num_words; x++) {
        string word;
        cin >> word;
        words.emplace(word);
    }
        
    cin >> queries;
    for (int x=0; x<queries; x++) {
        string word;
        cin >> word;        
        cout << words.count(word) << endl;
    }        
        
    return 0;
}
