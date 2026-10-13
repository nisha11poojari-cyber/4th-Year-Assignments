
#include <stdio.h>

#define MAX 16

void add(int n, int A[MAX][MAX], int B[MAX][MAX],
         int C[MAX][MAX]) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void sub(int n, int A[MAX][MAX], int B[MAX][MAX],
         int C[MAX][MAX]) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int n, int A[MAX][MAX], int B[MAX][MAX],
              int C[MAX][MAX]) {
    int i, j, k, h;
    int A11[MAX][MAX], A12[MAX][MAX];
    int A21[MAX][MAX], A22[MAX][MAX];
    int B11[MAX][MAX], B12[MAX][MAX];
    int B21[MAX][MAX], B22[MAX][MAX];
    int M1[MAX][MAX], M2[MAX][MAX];
    int M3[MAX][MAX], M4[MAX][MAX];
    int M5[MAX][MAX], M6[MAX][MAX];
    int M7[MAX][MAX], X[MAX][MAX], Y[MAX][MAX];
    int T1[MAX][MAX], T2[MAX][MAX];

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    h = n / 2;

    for (i = 0; i < h; i++) {
        for (j = 0; j < h; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + h];
            A21[i][j] = A[i + h][j];
            A22[i][j] = A[i + h][j + h];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + h];
            B21[i][j] = B[i + h][j];
            B22[i][j] = B[i + h][j + h];
        }
    }

    // M1 = (A11 + A22)(B11 + B22)
    add(h, A11, A22, X);
    add(h, B11, B22, Y);
    strassen(h, X, Y, M1);

    // M2 = (A21 + A22)B11
    add(h, A21, A22, X);
    strassen(h, X, B11, M2);

    // M3 = A11(B12 - B22)
    sub(h, B12, B22, Y);
    strassen(h, A11, Y, M3);

    // M4 = A22(B21 - B11)
    sub(h, B21, B11, Y);
    strassen(h, A22, Y, M4);

    // M5 = (A11 + A12)B22
    add(h, A11, A12, X);
    strassen(h, X, B22, M5);

    // M6 = (A21 - A11)(B11 + B12)
    sub(h, A21, A11, X);
    add(h, B11, B12, Y);
    strassen(h, X, Y, M6);

    // M7 = (A12 - A22)(B21 + B22)
    sub(h, A12, A22, X);
    add(h, B21, B22, Y);
    strassen(h, X, Y, M7);

    // C11 = M1 + M4 - M5 + M7
    add(h, M1, M4, T1);
    sub(h, T1, M5, T2);
    add(h, T2, M7, T1);

    // C12 = M3 + M5
    add(h, M3, M5, T2);

    // C21 = M2 + M4
    add(h, M2, M4, X);

    // C22 = M1 - M2 + M3 + M6
    sub(h, M1, M2, Y);
    add(h, Y, M3, Y);
    add(h, Y, M6, Y);

    for (i = 0; i < h; i++) {
        for (j = 0; j < h; j++) {
            C[i][j] = T1[i][j];
            C[i][j + h] = T2[i][j];
            C[i + h][j] = X[i][j];
            C[i + h][j + h] = Y[i][j];
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int n, i, j;

    printf("Enter the order of square matrices (power of 2, max 16): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX || (n & (n - 1)) != 0) {
        printf("Invalid size. Enter a power of 2 between 1 and 16.\n");
        return 0;
    }

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    strassen(n, A, B, C);

    printf("Product matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d\t", C[i][j]);
        printf("\n");
    }

    return 0;
}
