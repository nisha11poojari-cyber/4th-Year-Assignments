
#include <stdio.h>

int main() {
    int arr[100], n, min, i;

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

    min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Minimum number = %d\n", min);

    return 0;
}
