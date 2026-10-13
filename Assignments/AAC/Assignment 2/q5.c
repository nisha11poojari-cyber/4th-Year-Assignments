#include <stdio.h>

#define INF 99999

int main() {
    int cost[20][20], visited[20] = {0};
    int n, i, j, edges = 0;
    int min, u = 0, v = 0, minCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (99999 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n - 1) {
        min = INF;
        u = -1;
        v = -1;

        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1) {
            printf("Minimum Spanning Tree is not possible.\n");
            return 0;
        }

        printf("%d - %d : %d\n", u + 1, v + 1, min);

        minCost += min;
        visited[v] = 1;
        edges++;
    }

    printf("Minimum cost = %d\n", minCost);

    return 0;
}