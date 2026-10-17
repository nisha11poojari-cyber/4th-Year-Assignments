
#include <stdio.h>

// Function to calculate factorial using iteration
long long factorial_iterative(int n) {
    long long fact = 1;

    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }

    return fact;
}

// Function to calculate factorial using recursion
long long factorial_recursive(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return n * factorial_recursive(n - 1);
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0 || n > 20) {
        printf("Please enter a number between 0 and 20.\n");
        return 0;
    }

    printf("Factorial using iteration = %lld\n",
           factorial_iterative(n));

    printf("Factorial using recursion = %lld\n",
           factorial_recursive(n));

    return 0;
}
