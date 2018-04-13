#include <limits.h>
#include <stdint.h>

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(char *S) {
    // write your code in C99 (gcc 4.8.2)
    int negative = 0;
    int32_t total = 0;
    
    while (*S == ' ')
        ++S;

    if (*S == '-') {
        negative = 1;
        ++S;
    }
        
    while (*S) {
        char digit = *S;
        if ((digit >= '0') && (digit <= '9'))
            total = total*10 + (digit - '0');
        else return 0;
        ++S;
    }
    if (negative)
        return -1 * total;
    else return total;
}
