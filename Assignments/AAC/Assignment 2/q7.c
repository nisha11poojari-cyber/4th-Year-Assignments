#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, capacity, i, w;
    int weight[20], profit[20];
    int dp[21][101];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weight and profit of each item:\n");
    for (i = 1; i <= n; i++) {
        printf("Item %d: ", i);
        scanf("%d %d", &weight[i], &profit[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    if (n < 1 || n > 20 || capacity < 0 || capacity > 100) {
        printf("Invalid input. Use 1-20 items and capacity 0-100.\n");
        return 0;
    }

    // Initialize DP table
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i] <= w)
                dp[i][w] = max(
                    profit[i] + dp[i - 1][w - weight[i]],
                    dp[i - 1][w]
                );
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("\nMaximum profit = %d\n", dp[n][capacity]);

    // Display selected items
    printf("Selected items: ");
    w = capacity;

    for (i = n; i >= 1; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("%d ", i);
            w -= weight[i];
        }
    }

    printf("\n");

    return 0;
}