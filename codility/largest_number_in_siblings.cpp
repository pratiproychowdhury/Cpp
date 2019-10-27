#include <queue>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    priority_queue<int> digits;
    
    while (N) {
        int number = N % 10;    
        N /= 10;
        digits.push(number);
        //cout << "number = " << number << " N = " << N << endl;
    }

    int result = 0;
    while (!digits.empty()) {
        int number = digits.top();
        digits.pop();
        result = result*10 + number;
    }
    //cout << "result = " << result << endl;
    return result;
}
