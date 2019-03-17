#include <algorithm>

class Interval {
    public:
        int a;
        int b;

    Interval(int x, int y) : a(x), b(y) {}
};

bool compare (Interval x, Interval y) {
    return (x.a < y.a);
}


int solution(vector<int> &A, vector<int> &B) {
    
    vector<Interval> data;
    vector<Interval> result;
    vector<Interval>::iterator thisInterval;
    data.reserve(A.size());
    
    // First store all intervals into a vector
    for (unsigned int i=0; i<A.size(); i++)
        data.push_back(Interval(A[i], B[i]));
 
    // Sort intervals by start
    sort(data.begin(), data.end(), compare);   
    
    // Prepare
    thisInterval = data.begin();
    result.push_back(Interval(thisInterval->a, thisInterval->b));
    thisInterval++;
 
    // Process intervals 
    Interval first = result.back();
    while (thisInterval != data.end()) {
        // Intervals are disjoint; add new interval to result
        if (first.b < thisInterval->a) {
            result.push_back(Interval(thisInterval->a, thisInterval->b));
        }
        // New interval can be joined into a larger interval
        else if (first.b < thisInterval->b) {
            int start = first.a;
            int end = thisInterval->b;
            result.pop_back();
            result.push_back(Interval(start, end));
        }
        // New interval is contained in first interval; ignore new interval
        
        first = result.back();
        thisInterval++;
    }
    
    return result.size();
}
