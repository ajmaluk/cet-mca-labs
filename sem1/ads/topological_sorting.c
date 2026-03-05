/**
 * @file topological_sorting.c
 * @brief Kahn's Algorithm for Topological Sorting of a DAG.
 */

#include <stdio.h>

#define DAG_MAX 20

void run_topological_sort() {
    int n, head = 0, tail = 0, count = 0;
    int adj[DAG_MAX][DAG_MAX], in_degree[DAG_MAX] = {0};
    int node_queue[DAG_MAX], result_order[DAG_MAX];

    printf("--- Topological Sort (DAG) ---");
    printf("\nTotal Vertices: ");
    scanf("%d", &n);

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
            if (adj[i][j]) in_degree[j]++;
        }
    }

    /* Enqueue nodes with zero in-degree */
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) node_queue[tail++] = i;
    }

    while (head < tail) {
        int u = node_queue[head++];
        result_order[count++] = u;

        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                in_degree[v]--;
                if (in_degree[v] == 0) node_queue[tail++] = v;
            }
        }
    }

    if (count != n) {
        printf("\nCycle detected: Graph is not a Directed Acyclic Graph!\n");
    } else {
        printf("\nOrdered Sequence: ");
        for (int i = 0; i < count; i++) {
            printf("%d%s", result_order[i], (i == count - 1) ? "" : " -> ");
        }
        printf("\n");
    }
}

int main() {
    run_topological_sort();
    return 0;
}
