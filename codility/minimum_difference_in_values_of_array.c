#include <limits.h>

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

void merge(int A[], int left, int middle, int right) {
    int first = left;
    int second = middle+1;
    int *tmp = malloc((right-left+1) * sizeof(int));
    int dest = 0;
    
    while ((first <= middle) && (second <= right)) {
        if (A[first] < A[second]) {
            tmp[dest] = A[first];
            first++;
        }
        else {
            tmp[dest] = A[second];
            second++;
        }
        dest++;
    }
    
    while (first <= middle) {
        tmp[dest] = A[first];
        first++; dest++;
    }
    while (second <= right) {
        tmp[dest] = A[second];
        second++; dest++;
    }
    
    for (int i=0; i<(right-left+1); i++)
        A[left+i] = tmp[i];
}

void sort(int A[], int left, int right) {
    int middle = (left+right)/2;
    
    if (right-left < 1)
        return;
        
    sort(A, left, middle);
    sort(A, middle+1, right);
    merge(A, left, middle, right);
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    // merge sort fills space and time requirements
    int min_dist = INT_MAX;
    sort(A, 0, N-1);
    
    for (int i=0; i<N-1; i++)
        if (abs(A[i]-A[i+1]) < min_dist)
            min_dist = abs(A[i]-A[i+1]);
    
    return min_dist;
}
