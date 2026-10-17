
#include <stdio.h>

int getMax(int arr[], int n) {
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

// Counting sort according to the current digit
void countSort(int arr[], int n, int exp, int ascending) {
    int output[100];
    int count[10] = {0};
    int i;

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Convert frequencies into cumulative counts
    if (ascending) {
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];
    } else {
        for (i = 8; i >= 0; i--)
            count[i] += count[i + 1];
    }

    // Build output array in stable order
    for (i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[--count[digit]] = arr[i];
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n, int ascending) {
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp, ascending);

        // Avoid integer overflow when advancing exp
        if (exp > max / 10)
            break;
    }
}

int main() {
    int arr[100], n, i;
    int asc[100], desc[100];

    printf("Enter the number of elements (max 100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid array size.\n");
        return 0;
    }

    printf("Enter non-negative integers:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        if (arr[i] < 0) {
            printf("Negative numbers are not supported.\n");
            return 0;
        }

        asc[i] = desc[i] = arr[i];
    }

    radixSort(asc, n, 1);
    radixSort(desc, n, 0);

    printf("Ascending order: ");
    for (i = 0; i < n; i++)
        printf("%d ", asc[i]);

    printf("\nDescending order: ");
    for (i = 0; i < n; i++)
        printf("%d ", desc[i]);

    printf("\n");
    return 0;
}
