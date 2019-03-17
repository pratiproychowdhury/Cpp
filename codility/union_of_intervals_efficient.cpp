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
    
    if (!A.size())
        return 0;
    else data.reserve(A.size());
    
    // First store all intervals into a vector
    for (unsigned int i=0; i<A.size(); i++)
        data.push_back(Interval(A[i], B[i]));
 
    // Sort intervals by start
    sort(data.begin(), data.end(), compare);   
    
    // Prepare
    vector<Interval>::iterator thisInterval = data.begin();
    Interval first = data.front();
    int processed_intervals = 1;
 
    // Process intervals
    thisInterval++;
    while (thisInterval != data.end()) {
        // Intervals are disjoint; add new interval to result
        if (first.b < thisInterval->a) {
            first.a = thisInterval->a;
            first.b = thisInterval->b;
            processed_intervals++;
        }
        // New interval can be joined into a larger interval
        else if (first.b < thisInterval->b)
            first.b = thisInterval->b;

        thisInterval++;
    }
    
    return processed_intervals;
}
