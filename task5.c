#include <stdio.h>

 

unsigned long long factorial(int n) {

    if (n == 0 || n == 1)

        return 1;

    return (unsigned long long)n * factorial(n - 1);

}

 

int main(void) {

    int n;

 

    printf("Enter a number: ");

    scanf("%d", &n);

 

    if (n < 0) {

        printf("Negative input is not allowed.\n");

        return 1;

    }

    if (n > 20) {

        printf("Please enter a number from 0 to 20.\n");

        return 1;

    }

 

    printf("Factorial of %d = %llu\n", n, factorial(n));

    return 0;

}