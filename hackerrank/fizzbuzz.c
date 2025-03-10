void fizzBuzz(int n) {
    for (int x=1; x<=n; x++) {
        bool flag = false;
        if (!(x%3)) {
            printf("Fizz");
            flag = true;
        }
        if (!(x%5)) {
            printf("Buzz");
            flag = true;
        }
        if (!flag)
            printf("%i", x);    
        printf("\n");
    }
}
