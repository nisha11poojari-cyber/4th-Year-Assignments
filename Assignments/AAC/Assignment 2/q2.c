#include <stdio.h>

int main() {
    int n, adj[20][20], indegree[20] = {0};
    int queue[20], front = 0, rear = -1;
    int order[20], count = 0;
    int i, j, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);

            if (adj[i][j] == 1)
                indegree[j]++;
        }
    }

    // Insert vertices with indegree 0 into queue
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[++rear] = i;
    }

    // Perform topological sorting
    while (front <= rear) {
        u = queue[front++];
        order[count++] = u;

        for (j = 0; j < n; j++) {
            if (adj[u][j] == 1) {
                indegree[j]--;

                if (indegree[j] == 0)
                    queue[++rear] = j;
            }
        }
    }

    if (count != n) {
        printf("Topological sorting is not possible.\n");
    } else {
        printf("Topological order: ");
        for (i = 0; i < count; i++)
            printf("%d ", order[i]);
        printf("\n");
    }

    return 0;
}