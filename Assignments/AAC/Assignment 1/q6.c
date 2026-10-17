
#include <stdio.h>

// Function to calculate the number of digits
int countDigits(int n) {
    int count = 0;

    do {
        count++;
        n = n / 10;
    } while (n != 0);

    return count;
}

// Function to calculate power using iteration
int powerIterative(int base, int exp) {
    int result = 1;

    for (int i = 0; i < exp; i++)
        result *= base;

    return result;
}

// Iterative method
int isArmstrongIterative(int n) {
    int original = n, sum = 0, digit;
    int digits = countDigits(n);

    while (n > 0) {
        digit = n % 10;
        sum += powerIterative(digit, digits);
        n = n / 10;
    }

    return sum == original;
}

// Recursive method to calculate power
int powerRecursive(int base, int exp) {
    if (exp == 0)
        return 1;

    return base * powerRecursive(base, exp - 1);
}

// Recursive method to calculate Armstrong sum
int armstrongSumRecursive(int n, int digits) {
    if (n == 0)
        return 0;

    return powerRecursive(n % 10, digits) +
           armstrongSumRecursive(n / 10, digits);
}

int isArmstrongRecursive(int n) {
    if (n < 0)
        return 0;

    int digits = countDigits(n);

    return armstrongSumRecursive(n, digits) == n;
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Negative numbers are not Armstrong numbers.\n");
        return 0;
    }

    if (isArmstrongIterative(n))
        printf("Iterative: Armstrong number\n");
    else
        printf("Iterative: Not an Armstrong number\n");

    if (isArmstrongRecursive(n))
        printf("Recursive: Armstrong number\n");
    else
        printf("Recursive: Not an Armstrong number\n");

    return 0;
}
