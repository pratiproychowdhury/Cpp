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


class Node {
    
    public:
        int number;
        vector<Node *> child;
    
    Node() {
        number = 1;
        child.reserve(26);
    }  
};


void add(Node &node, string contact) {

    int which = contact[0]-'a';

    if (contact[0] == '\0')
        return;
       
    if (node.child[which] == NULL) {
        node.child[which] = new Node();
    }
    else {
        node.child[which]->number++;
    }
        
    add(*node.child[which], contact.substr(1));    
}


int search(Node &node, string contact) {
    
    if (contact[0] == '\0')
        return node.number;
    
    int which = contact[0]-'a';
    
    if (node.child[which] == NULL) {
        return 0;
    }
    
    return search(*node.child[which], contact.substr(1));
}

int main(){
    int n;
    Node trie;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        if (op == "add")
            add(trie, contact);
        if (op == "find")
            cout << search(trie, contact) << endl;
    }
    return 0;
}
