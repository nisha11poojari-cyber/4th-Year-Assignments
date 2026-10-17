
#include <stdio.h>

int main() {
    int arr[100], count[201] = {0};
    int n, i, min, max, range, k = 0;

    printf("Enter the number of elements (max 100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid array size.\n");
        return 0;
    }

    printf("Enter the array elements (-100 to 100):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        if (arr[i] < -100 || arr[i] > 100) {
            printf("Elements must be between -100 and 100.\n");
            return 0;
        }
    }

    min = max = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    range = max - min + 1;

    // Count occurrences of each element
    for (i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }

    // Ascending order
    printf("Ascending order: ");
    for (i = 0; i < range; i++) {
        while (count[i] > 0) {
            printf("%d ", i + min);
            count[i]--;
        }
    }

    // Rebuild the frequency array
    for (i = 0; i < n; i++) {
        count[arr[i] - min]++;
    }

    // Descending order
    printf("\nDescending order: ");
    for (i = range - 1; i >= 0; i--) {
        while (count[i] > 0) {
            printf("%d ", i + min);
            count[i]--;
        }
    }

    printf("\n");
    return 0;
}
