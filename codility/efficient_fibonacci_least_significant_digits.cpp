int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int first = 0;
    int second = 1;
    int temp;
    
    if (!N)
        return 0;
    
    for (int i=1; i<N; i++) {
        if (!(i%10)) {              // 10 is chosen because with this value an overflow in temp is still avoided
            // these are the operations to be avoided since they are the costliest in terms of time
            first %= 1000000;
            second %= 1000000;
        }        
        temp = first + second;
        first = second;
        second = temp;
    }
    
    return second%1000000;
}
