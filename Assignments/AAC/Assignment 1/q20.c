
#include <stdio.h>

int main() {
    int arr[100], n, i, j, key;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid array size.\n");
        return 0;
    }

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Insertion sort in ascending order
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    printf("Ascending order: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Insertion sort in descending order
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    printf("\nDescending order: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
