#include <stdio.h>

int main(void) {

    int n;
    long long previous = 0, current = 1;
    
    printf("Enter number of terms: ");

    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

 

    if (n <= 0 || n > 40) {

        printf("Enter a number of terms from 1 to 40.\n");

        return 1;

    }

 

    printf("Fibonacci series: ");

    for (int i = 0; i < n; i++) {
        printf("%lld ", previous);
        long long next = previous + current;
        previous = current;
        current = next;
    }

    printf("\n");

    return 0;

}
