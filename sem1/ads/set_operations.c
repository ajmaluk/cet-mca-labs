/**
 * @file set_operations.c
 * @brief Implementation of Disjoint Set Union (DSU) for SET operations.
 * 
 * Includes MakeSet, Find (with Path Compression), and Union (by linking).
 */

#include <stdio.h>
#include <stdbool.h>

#define SET_MAX 100

/* State encapsulation */
int set_elements[SET_MAX];
int parent_map[SET_MAX];
int global_count = 0;

/**
 * @brief Initialize a new disjoint set for a value.
 */
void initialize_set(int val) {
    if (global_count >= SET_MAX) return;
    set_elements[global_count] = val;
    parent_map[global_count] = val;
    global_count++;
}

/**
 * @brief Find the root representative of a set using recursion.
 */
int find_representative(int val) {
    for (int i = 0; i < global_count; i++) {
        if (set_elements[i] == val) {
            if (parent_map[i] == val) return val;
            /* Recursive path compression for efficiency */
            return parent_map[i] = find_representative(parent_map[i]);
        }
    }
    return -1;
}

/**
 * @brief Performs union of two disjoint sets.
 */
void perform_union(int val1, int val2) {
    int root1 = find_representative(val1);
    int root2 = find_representative(val2);

    if (root1 != -1 && root2 != -1 && root1 != root2) {
        /* Merge root2 into root1 */
        for (int i = 0; i < global_count; i++) {
            if (set_elements[i] == root2) {
                parent_map[i] = root1;
                break;
            }
        }
        printf("\nAction: Unified sets of %d and %d.", val1, val2);
    } else {
        printf("\nAction: %d and %d are already in the same set.", val1, val2);
    }
}

/**
 * @brief Visualizes the current disjoint set structure.
 */
void print_disjoint_sets() {
    bool is_accounted[SET_MAX] = {false};
    printf("\n\n--- Current Structure ---\n");
    
    for (int i = 0; i < global_count; i++) {
        int root = find_representative(set_elements[i]);
        
        /* If this is a root and hasn't been printed yet */
        if (!is_accounted[i] && set_elements[i] == root) {
            printf("{ %d", set_elements[i]);
            for (int j = 0; j < global_count; j++) {
                if (set_elements[j] != root && find_representative(set_elements[j]) == root) {
                    printf(", %d", set_elements[j]);
                }
            }
            printf(" } \n");
        }
    }
}

int main() {
    printf("--- Disjoint Set Operations (Refined) ---");
    
    /* Initialize basic elements */
    for (int i = 1; i <= 5; i++) initialize_set(i);

    perform_union(1, 2);
    perform_union(3, 4);
    perform_union(2, 3);
    perform_union(5, 5); /* Self check */

    print_disjoint_sets();

    return 0;
}
