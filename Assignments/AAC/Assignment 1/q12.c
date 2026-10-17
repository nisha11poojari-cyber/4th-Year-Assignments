
#include <stdio.h>

// Iterative method
long long powerIterative(int x, int n) {
    long long result = 1;

    for (int i = 1; i <= n; i++) {
        result = result * x;
    }

    return result;
}

// Recursive method
long long powerRecursive(int x, int n) {
    if (n == 0)
        return 1;

    return x * powerRecursive(x, n - 1);
}

int main() {
    int x, n;

    printf("Enter the value of x: ");
    scanf("%d", &x);

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n < 0 || n > 62) {
        printf("Enter a non-negative exponent up to 62.\n");
        return 0;
    }

    printf("Power using iteration = %lld\n",
           powerIterative(x, n));

    printf("Power using recursion = %lld\n",
           powerRecursive(x, n));

    return 0;
}
