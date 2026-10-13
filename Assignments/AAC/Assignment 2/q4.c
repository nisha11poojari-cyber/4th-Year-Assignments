#include <stdio.h>
#include <stdlib.h>

int board[20], n;

// Check whether a queen can be placed safely
int place(int row, int col) {
    int i;

    for (i = 1; i < row; i++) {
        if (board[i] == col ||
            abs(board[i] - col) == abs(i - row)) {
            return 0;
        }
    }

    return 1;
}

// Solve N-Queens using backtracking
void solve(int row) {
    int col, i, j;

    if (row > n) {
        printf("\nSolution:\n");

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (board[i] == j)
                    printf("Q ");
                else
                    printf("- ");
            }
            printf("\n");
        }

        return;
    }

    for (col = 1; col <= n; col++) {
        if (place(row, col)) {
            board[row] = col;
            solve(row + 1);
            board[row] = 0;
        }
    }
}

int main() {
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    if (n < 1 || n > 20) {
        printf("Enter N between 1 and 20.\n");
        return 0;
    }

    solve(1);

    return 0;
}