
#include <stdio.h>

long long power(int x, int n) {
    long long result = 1;

    while (n > 0) {
        if (n % 2 == 1)
            result = result * x;

        x = x * x;
        n = n / 2;
    }

    return result;
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

    printf("%d^%d = %lld\n", x, n, power(x, n));

    return 0;
}
