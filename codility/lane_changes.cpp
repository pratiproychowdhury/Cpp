#include <bitset>
#include <limits> 
#include <algorithm>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int next(vector<int> &A, unsigned int presentSegment, int presentLane, int changes) {

    if (presentSegment==A.size())
        return changes;
        
    bitset<8> lanes(A[presentSegment+1]);
    int a, b, c;
    
    if (lanes.test(presentLane))
        a = next(A, presentSegment+1, presentLane, changes);
    else a = numeric_limits<int>::max(); 
    
    if ((presentLane) && (lanes.test(presentLane-1)))
        b = next(A, presentSegment+1, presentLane-1, changes+1);
    else b = numeric_limits<int>::max();
    
    if ((presentLane<7) && (lanes.test(presentLane+1)))
        c = next(A, presentSegment+1, presentLane+1, changes+1);
    else c = numeric_limits<int>::max();
    
    int temp = min(a, b);
    return min(temp,c);
}


int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int changes = numeric_limits<int>::max();
    
    for (int i=0; i<8; i++)
        changes = min(changes, next(A, -1, i, 0));
 
    if (changes==numeric_limits<int>::max())
        return -1;
    else return changes;
}
