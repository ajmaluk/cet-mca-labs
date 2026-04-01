/**
 * @file bit_string.c
 * @brief Implementation of Set operations using Bitstring representation.
 * 
 * Concept: Each bit in an integer or array represents the presence (1) or 
 * absence (0) of an element in a predefined universal set.
 */

#include <stdio.h>

#define UNIVERSE_SIZE 8 /* Universal set U = {0, 1, 2, ..., 7} */

/* Helper to render the set contents */
void render_set(int bit_array[], const char *set_label) {
    printf("%-15s (Bits): ", set_label);
    for (int i = UNIVERSE_SIZE - 1; i >= 0; i--) {
        printf("%d", bit_array[i]);
    }
    
    printf(" | Elements: { ");
    bool is_first = true;
    for (int i = 0; i < UNIVERSE_SIZE; i++) {
        if (bit_array[i]) {
            if (!is_first) printf(", ");
            printf("%d", i);
            is_first = false;
        }
    }
    printf(" }\n");
}

int main() {
    /* Set A = {1, 3, 4}, Set B = {2, 3, 6} */
    int set_a[UNIVERSE_SIZE] = {0, 1, 0, 1, 1, 0, 0, 0}; 
    int set_b[UNIVERSE_SIZE] = {0, 0, 1, 1, 0, 0, 1, 0}; 
    int set_result[UNIVERSE_SIZE];

    printf("--- Set Operations (Bitstring Logic) ---\n");
    printf("Universal Set U = {0, 1, 2, 3, 4, 5, 6, 7}\n\n");

    render_set(set_a, "Set A");
    render_set(set_b, "Set B");
    printf("\n");

    /* Union: A OR B */
    for (int i = 0; i < UNIVERSE_SIZE; i++) 
        set_result[i] = set_a[i] | set_b[i];
    render_set(set_result, "Union (A ∪ B)");

    /* Intersection: A AND B */
    for (int i = 0; i < UNIVERSE_SIZE; i++) 
        set_result[i] = set_a[i] & set_b[i];
    render_set(set_result, "Intersection (A ∩ B)");

    /* Difference: A AND (NOT B) */
    for (int i = 0; i < UNIVERSE_SIZE; i++) 
        set_result[i] = set_a[i] & (!set_b[i]);
    render_set(set_result, "Difference (A - B)");

    return 0;
}
