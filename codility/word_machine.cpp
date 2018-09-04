#include <stack>
#include <math.h>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    stack<int> data;
    int max_num = pow(2, 20) - 1;
    
    while (S.length()) {
        if (S.find("DUP") == 0) {
            int i = data.top();
            data.push(i);
            S.erase(0,4);
        }
        else if (S.find("POP") == 0) {
            data.pop();
            S.erase(0,4);
        }        
        else if (S.find("+") == 0) {
            int i = data.top();
            data.pop();
            int j = data.top();
            data.pop();
            int sum = i+j;
            if ((sum<i) || (sum<j) || (sum>max_num))
                return -1;
            data.push(sum);
            S.erase(0,2);
        }
        else if (S.find("-") == 0) {
            int i = data.top();
            data.pop();
            int j = data.top();
            data.pop();
            int minus = i-j;
            if ((minus>i) || (minus>j) || (j>i))
                return -1;
            data.push(minus);     
            S.erase(0,2);
        }
        else {
            int pos = S.find(" ");
            int num = stoul(S.substr(0, pos));
            if (num > max_num)
                return -1;
            data.push(num);
            S.erase(0,pos+1);
        }
    }
    return data.top();
}
