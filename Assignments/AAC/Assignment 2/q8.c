
#include <stdio.h>

#define INF 99999

int main() {
    int cost[20][20], distance[20], visited[20];
    int n, source, i, j, count, min, next;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (99999 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter source vertex (1 to %d): ", n);
    scanf("%d", &source);

    if (n < 1 || n > 20 || source < 1 || source > n) {
        printf("Invalid input.\n");
        return 0;
    }

    source--;

    for (i = 0; i < n; i++) {
        distance[i] = cost[source][i];
        visited[i] = 0;
    }

    distance[source] = 0;
    visited[source] = 1;

    for (count = 1; count < n; count++) {
        min = INF;
        next = -1;

        for (i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < min) {
                min = distance[i];
                next = i;
            }
        }

        if (next == -1)
            break;

        visited[next] = 1;

        for (i = 0; i < n; i++) {
            if (!visited[i] &&
                cost[next][i] != INF &&
                distance[next] != INF &&
                distance[next] + cost[next][i] < distance[i]) {
                distance[i] = distance[next] + cost[next][i];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source + 1);
    printf("Vertex\tDistance\n");

    for (i = 0; i < n; i++) {
        printf("%d\t", i + 1);

        if (distance[i] == INF)
            printf("Unreachable\n");
        else
            printf("%d\n", distance[i]);
    }

    return 0;
}
