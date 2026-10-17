
#include <stdio.h>

// Iterative method
int isPalindromeIterative(int n) {
    int original = n, reverse = 0, digit;

    if (n < 0)
        return 0;

    while (n > 0) {
        digit = n % 10;
        reverse = reverse * 10 + digit;
        n = n / 10;
    }

    return original == reverse;
}

// Recursive helper function
int reverseNumber(int n, int reverse) {
    if (n == 0)
        return reverse;

    return reverseNumber(n / 10, reverse * 10 + n % 10);
}

// Recursive method
int isPalindromeRecursive(int n) {
    if (n < 0)
        return 0;

    return n == reverseNumber(n, 0);
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (isPalindromeIterative(n))
        printf("Iterative: Palindrome number\n");
    else
        printf("Iterative: Not a palindrome number\n");

    if (isPalindromeRecursive(n))
        printf("Recursive: Palindrome number\n");
    else
        printf("Recursive: Not a palindrome number\n");

    return 0;
}
