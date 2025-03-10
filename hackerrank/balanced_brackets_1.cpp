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

bool is_balanced(string expression) {
    
   stack<char> brackets;
    
   for (int i=0; i<expression.size(); i++) {
        
        if ((expression[i] == '(') || (expression[i] == '[') || (expression[i] == '{')) {
            brackets.push(expression[i]);
            //cout << "Stacking " << expression[i] << "\n";
        }
        
        if (expression[i] == ')') {
            if (brackets.empty())
                return false;            
            if (brackets.top() == '(') {
                brackets.pop();
                //cout << "Popping (\n";
            }
            else {
                //cout << "Looking for a ( in stack but not found. Found a " << brackets.top() << "\n";   
                return false;
            }
        }
        
        if (expression[i] == ']') {
            if (brackets.empty())
                return false;
            if (brackets.top() == '[') {
                brackets.pop();
                //cout << "Popping [\n";
            }
            else {
                //cout << "Looking for a [ in stack but not found. Found a " << brackets.top() << "\n";   
                return false;
            }
        }
        
        if (expression[i] == '}') {
            if (brackets.empty())
                return false;
            if (brackets.top() == '{') {
                brackets.pop();
                //cout << "Popping {\n";
            }
            else {
                //cout << "Looking for a { in stack but not found. Found a " << brackets.top() << "\n";   
                return false;
            }
        }
    }
    
    if (brackets.empty())
        return true;
    
    return false;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
