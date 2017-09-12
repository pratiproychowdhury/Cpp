#include <bitset>

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    bitset<31> binary (N);
    int max = 0, current = 0, start = 0;
    while (!binary[start])
        start++;
    for (int i=start; i<31; i++) {
        if (binary[i]) {
            if (current > max)
                max = current;
            current = 0;
        }
        else 
            current++;
    }
    return max;
}
