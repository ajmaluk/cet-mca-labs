/**
 * @file prims_algorithm.c
 * @brief Implementation of Prim's MST algorithm for CET MCA.
 */

#include <stdio.h>
#include <stdbool.h>

#define NODE_MAX 20
#define INF_VAL 9999

int main() {
    int total_nodes;
    bool is_visited[NODE_MAX] = {false};
    int cost_matrix[NODE_MAX][NODE_MAX];
    int mst_total = 0, edge_tracker = 0;

    printf("--- Prim's MST Logic ---");
    printf("\nEnter vertex count: ");
    scanf("%d", &total_nodes);

    printf("Enter Cost Adjacency Matrix (0 for no edge):\n");
    for (int i = 0; i < total_nodes; i++) {
        for (int j = 0; j < total_nodes; j++) {
            scanf("%d", &cost_matrix[i][j]);
        }
    }

    /* Start from the first node */
    is_visited[0] = true;

    printf("\nMST Selected Edges:\n");
    while (edge_tracker < total_nodes - 1) {
        int minimum_cost = INF_VAL;
        int u_node = -1, v_node = -1;

        /* Find the cheapest edge extending the current MST tree */
        for (int i = 0; i < total_nodes; i++) {
            if (is_visited[i]) {
                for (int j = 0; j < total_nodes; j++) {
                    if (!is_visited[j] && cost_matrix[i][j] != 0 && cost_matrix[i][j] < minimum_cost) {
                        minimum_cost = cost_matrix[i][j];
                        u_node = i;
                        v_node = j;
                    }
                }
            }
        }

        if (v_node == -1) {
            printf("\nSystem: Error in graph connectivity. Path broken.\n");
            return 1;
        }

        printf("[%d] -- [%d] (Weight: %d)\n", u_node, v_node, minimum_cost);
        is_visited[v_node] = true;
        mst_total += minimum_cost;
        edge_tracker++;
    }

    printf("\nTotal Prim's MST Weight: %d\n", mst_total);
    return 0;
}
