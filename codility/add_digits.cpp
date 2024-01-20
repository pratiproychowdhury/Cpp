int solution(int N, int K) {
    int increment = 9 - N / 100;
    if (K > increment) {
        N += increment*100;
        K -= increment;
    }
    else
        return N + K*100;

    increment = 9 - ((N/10) % 10);
    if (K > increment) {
        N += increment*10;
        K -= increment;
    }
    else
        return N + K*10;

    increment = 9 - (N%10);
    return (K > increment ? 999 : N+K);        
}
