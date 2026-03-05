/**
 * @file dfs.c
 * @brief Depth-First Search (DFS) graph traversal implementation.
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX_V 20

int visited_status[MAX_V] = {0};
int traversal_stack[MAX_V];
int top_idx = -1;

void execute_dfs(int n, int adj[MAX_V][MAX_V], int start_node) {
    printf("\nDFS Sequence from %d: ", start_node);
    
    traversal_stack[++top_idx] = start_node;

    while (top_idx != -1) {
        int u = traversal_stack[top_idx--];

        if (!visited_status[u]) {
            printf("%d ", u);
            visited_status[u] = 1;

            /* Push neighbors in reverse for standard display order */
            for (int v = n - 1; v >= 0; v--) {
                if (adj[u][v] == 1 && !visited_status[v]) {
                    traversal_stack[++top_idx] = v;
                }
            }
        }
    }
    printf("\n");
}

int main() {
    int n, start_v;
    int adj[MAX_V][MAX_V];

    printf("--- DFS Traversal (Refined) ---");
    printf("\nEnter node count: ");
    scanf("%d", &n);

    printf("Adjacency Matrix Input:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Start node: ");
    scanf("%d", &start_v);

    if (start_v >= 0 && start_v < n) {
        execute_dfs(n, adj, start_v);
    } else {
        printf("Invalid node index.\n");
    }

    return 0;
}
