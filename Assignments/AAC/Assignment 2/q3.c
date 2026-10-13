#include <stdio.h>

#define INF 99999

int main() {
    int n, cost[20][20];
    int i, j, k;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (99999 for infinity):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Floyd-Warshall algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][k] != INF && cost[k][j] != INF &&
                    cost[i][k] + cost[k][j] < cost[i][j]) {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }

    printf("\nAll-Pairs Shortest Path Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (cost[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }

    return 0;
}