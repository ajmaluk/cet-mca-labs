/**
 * @file kruskal_algorithm.c
 * @brief Implementation of Kruskal's MST algorithm for CET MCA.
 * 
 * Uses a greedy approach with Disjoint Set Union (DSU) to find the MST.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 20
#define INF_WEIGHT 9999

int set_parent[MAX_NODES];

/**
 * @brief Find the root of a set with path compression.
 */
int find_root(int i) {
    if (set_parent[i] == i) return i;
    return set_parent[i] = find_root(set_parent[i]);
}

/**
 * @brief Union of two sets by root assignment.
 */
void unite_sets(int i, int j) {
    int root_a = find_root(i);
    int root_b = find_root(j);
    if (root_a != root_b) set_parent[root_a] = root_b;
}

int main() {
    int n, edge_idx = 0;
    int mst_weight = 0, edges_count = 0;
    int cost_matrix[MAX_NODES][MAX_NODES];
    
    /* Edge representation: node1, node2, weight */
    int edge_list[MAX_NODES * MAX_NODES][3];

    printf("--- Kruskal's MST Logic ---");
    printf("\nEnter node count: ");
    scanf("%d", &n);

    printf("Enter Cost Adjacency Matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost_matrix[i][j]);
            /* Store only once for undirected edges */
            if (j > i && cost_matrix[i][j] != 0) {
                edge_list[edge_idx][0] = i;
                edge_list[edge_idx][1] = j;
                edge_list[edge_idx][2] = cost_matrix[i][j];
                edge_idx++;
            }
        }
    }

    /* Initial DSU state */
    for (int i = 0; i < n; i++) set_parent[i] = i;

    printf("\nMST Selected Edges:\n");
    while (edges_count < n - 1) {
        int min_val = INF_WEIGHT;
        int u = -1, v = -1, target_idx = -1;

        /* Find globally minimum edge among remaining edges */
        for (int i = 0; i < edge_idx; i++) {
            if (edge_list[i][2] < min_val) {
                min_val = edge_list[i][2];
                u = edge_list[i][0];
                v = edge_list[i][1];
                target_idx = i;
            }
        }

        if (target_idx == -1) break; /* No more edges */

        /* If doesn't form a cycle */
        if (find_root(u) != find_root(v)) {
            printf("[%d] -- [%d] (Weight: %d)\n", u, v, min_val);
            mst_weight += min_val;
            edges_count++;
            unite_sets(u, v);
        }

        /* Eliminate edge from further consideration */
        edge_list[target_idx][2] = INF_WEIGHT;
    }

    if (edges_count < n - 1) {
        printf("\nWarning: Disconnected graph detected. MST is incomplete.\n");
    } else {
        printf("\nTotal Kruskal MST Weight: %d\n", mst_weight);
    }

    return 0;
}
