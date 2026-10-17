
#include <stdio.h>

// Iterative method
int sumIterative(int n) {
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    return sum;
}

// Recursive method
int sumRecursive(int n) {
    if (n == 0)
        return 0;

    return n + sumRecursive(n - 1);
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Enter a non-negative integer.\n");
        return 0;
    }

    printf("Sum using iteration = %d\n", sumIterative(n));
    printf("Sum using recursion = %d\n", sumRecursive(n));

    return 0;
}
