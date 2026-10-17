
#include <stdio.h>

// Iterative binary search
int binarySearchIterative(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// Recursive binary search
int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearchRecursive(arr, mid + 1, high, key);
    else
        return binarySearchRecursive(arr, low, mid - 1, key);
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

    printf("Enter elements in ascending order:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to search: ");
    scanf("%d", &key);

    result1 = binarySearchIterative(arr, n, key);
    result2 = binarySearchRecursive(arr, 0, n - 1, key);

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
