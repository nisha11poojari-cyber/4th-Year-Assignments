
#include <stdio.h>

// Iterative method
int sequentialSearchIterative(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

// Recursive method
int sequentialSearchRecursive(int arr[], int n, int key, int i) {
    if (i == n)
        return -1;

    if (arr[i] == key)
        return i;

    return sequentialSearchRecursive(arr, n, key, i + 1);
}

int main() {
    int arr[100], n, key, i;
    int result1, result2;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid array size.\n");
        return 0;
    }

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to search: ");
    scanf("%d", &key);

    result1 = sequentialSearchIterative(arr, n, key);
    result2 = sequentialSearchRecursive(arr, n, key, 0);

    if (result1 != -1)
        printf("Iterative: Element found at position %d\n", result1 + 1);
    else
        printf("Iterative: Element not found\n");

    if (result2 != -1)
        printf("Recursive: Element found at position %d\n", result2 + 1);
    else
        printf("Recursive: Element not found\n");

    return 0;
}
