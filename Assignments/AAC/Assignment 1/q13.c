
#include <stdio.h>

int main() {
    int a[10][10], b[10][10], sum[10][10], trans[10][10];
    int r, c, i, j;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);

    if (r < 1 || r > 10 || c < 1 || c > 10) {
        printf("Invalid matrix size.\n");
        return 0;
    }

    // Read first matrix
    printf("Enter elements of first matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Read second matrix
    printf("Enter elements of second matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Matrix addition
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    // Transpose of first matrix
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            trans[j][i] = a[i][j];
        }
    }

    // Display sum
    printf("\nSum of matrices:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }

    // Display transpose
    printf("\nTranspose of first matrix:\n");
    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++) {
            printf("%d\t", trans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
