
#include <stdio.h>
#include <string.h>

// Iterative method
int isPalindromeIterative(char str[]) {
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j) {
        if (str[i] != str[j])
            return 0;

        i++;
        j--;
    }

    return 1;
}

// Recursive method
int isPalindromeRecursive(char str[], int i, int j) {
    if (i >= j)
        return 1;

    if (str[i] != str[j])
        return 0;

    return isPalindromeRecursive(str, i + 1, j - 1);
}

int main() {
    char str[100];
    int len;

    printf("Enter a string: ");
    scanf("%99s", str);

    len = strlen(str);

    if (isPalindromeIterative(str))
        printf("Iterative: Palindrome string\n");
    else
        printf("Iterative: Not a palindrome string\n");

    if (isPalindromeRecursive(str, 0, len - 1))
        printf("Recursive: Palindrome string\n");
    else
        printf("Recursive: Not a palindrome string\n");

    return 0;
}
