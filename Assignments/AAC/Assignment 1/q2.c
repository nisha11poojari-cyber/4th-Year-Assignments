
#include <stdio.h>

// Iterative method
int fibonacci_iterative(int n) {
    int a = 0, b = 1, c;

    if (n == 1)
        return 0;

    if (n == 2)
        return 1;

    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

// Recursive method
int fibonacci_recursive(int n) {
    if (n == 1)
        return 0;

    if (n == 2)
        return 1;

    return fibonacci_recursive(n - 1) +
           fibonacci_recursive(n - 2);
}

int main() {
    int n;

    printf("Enter the position n: ");
    scanf("%d", &n);

    if (n < 1 || n > 47) {
        printf("Enter a position between 1 and 47.\n");
        return 0;
    }

    printf("Fibonacci number using iteration = %d\n",
           fibonacci_iterative(n));

    printf("Fibonacci number using recursion = %d\n",
           fibonacci_recursive(n));

    return 0;
}
