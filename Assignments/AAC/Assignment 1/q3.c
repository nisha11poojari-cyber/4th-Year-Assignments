
#include <stdio.h>

// Function to check whether a number is prime
int isPrime(int num) {
    if (num < 2)
        return 0;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }

    return 1;
}

// Iterative method
int nthPrimeIterative(int n) {
    int count = 0;
    int num = 1;

    while (count < n) {
        num++;

        if (isPrime(num))
            count++;
    }

    return num;
}

// Recursive method
int nthPrimeRecursive(int n, int num, int count) {
    if (count == n && isPrime(num))
        return num;

    num++;

    if (isPrime(num))
        count++;

    if (count == n)
        return num;

    return nthPrimeRecursive(n, num, count);
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Enter a positive integer.\n");
        return 0;
    }

    printf("Nth prime using iteration = %d\n",
           nthPrimeIterative(n));

    printf("Nth prime using recursion = %d\n",
           nthPrimeRecursive( n, 2, 1));

    return 0;
}
