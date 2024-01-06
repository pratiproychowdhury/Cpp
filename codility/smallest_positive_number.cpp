/*
Write a function:
int solution(vector<int> &A);
that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.
For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.
Given A = [1, 2, 3], the function should return 4.
Given A = [−1, −3], the function should return 1.
Write an efficient algorithm for the following assumptions:
N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
*/

#include <queue>

int solution(vector<int> &A) {
    priority_queue<int, vector<int>, greater<int> > minheap;
    
    for (auto& x : A)
        minheap.emplace(x);

    for (int z = 1; z < 100000; z++) {
        if (minheap.empty())
            return z;

        while (minheap.top() < z) {
            minheap.pop();
            if (minheap.empty())
                return z;
        }           

        if (minheap.top() > z)
            return z;
    }
    return 100000;
}
