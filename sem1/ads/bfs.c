/**
 * @file bfs.c
 * @brief Breadth-First Search (BFS) graph traversal implementation.
 * 
 * Optimized with adjacency matrix representation and queue management.
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 20

int visited_nodes[MAX_VERTICES] = {0};
int bfs_queue[MAX_VERTICES];
int head_ptr = 0, tail_ptr = 0;

/**
 * @brief Performs BFS on the graph.
 * @param n Total vertices.
 * @param adj_matrix Adjacency matrix.
 * @param start_node Entry vertex.
 */
void execute_bfs(int n, int adj_matrix[MAX_VERTICES][MAX_VERTICES], int start_node) {
    printf("\nBFS Sequence from %d: ", start_node);
    
    bfs_queue[tail_ptr++] = start_node;
    visited_nodes[start_node] = 1;

    while (head_ptr < tail_ptr) {
        int u = bfs_queue[head_ptr++];
        printf("%d ", u);

        for (int v = 0; v < n; v++) {
            if (adj_matrix[u][v] == 1 && !visited_nodes[v]) {
                bfs_queue[tail_ptr++] = v;
                visited_nodes[v] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, start_v;
    int adj[MAX_VERTICES][MAX_VERTICES];

    printf("--- BFS Traversal (Refined) ---");
    printf("\nEnter node count: ");
    scanf("%d", &n);

    printf("Enter Adjacency Matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter root vertex: ");
    scanf("%d", &start_v);

    if (start_v >= 0 && start_v < n) {
        execute_bfs(n, adj, start_v);
    } else {
        printf("Out of range vertex.\n");
    }

    return 0;
}
