/**
 * @file array.c
 * @brief Professional array manipulation implementation for CET MCA.
 * 
 * Includes creation, insertion, reversal (recursive), and bubble sort.
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX_CAPACITY 100

/* Global array state */
int data_array[MAX_CAPACITY];
int element_count = 0;

/* Function prototypes */
void populate_array();
void print_array();
void handle_insertion();
void reverse_recursively(int start_idx, int end_idx);
void bubble_sort();
void insert_at_index(int index, int value);

int main() {
    printf("--- Array Utility Program (Refined) ---\n");
    populate_array();
    
    printf("\nInitial Data Set:");
    print_array();
    
    reverse_recursively(0, element_count - 1);
    printf("\nData after Reversal:");
    print_array();
    
    bubble_sort();
    printf("\nData after Sorting:");
    print_array();
    
    handle_insertion();
    printf("\nFinal Data Set:");
    print_array();
    
    return 0;
}

void populate_array() {
    printf("Enter number of elements (max %d): ", MAX_CAPACITY);
    scanf("%d", &element_count);
    
    if (element_count > MAX_CAPACITY) {
        printf("Capping elements at %d.\n", MAX_CAPACITY);
        element_count = MAX_CAPACITY;
    }
    
    printf("Enter %d integers:\n", element_count);
    for (int i = 0; i < element_count; i++) {
        scanf("%d", &data_array[i]);
    }
}

void print_array() {
    if (element_count == 0) {
        printf("\n[ Empty Array ]\n");
        return;
    }
    printf("\n[ ");
    for (int i = 0; i < element_count; i++) {
        printf("%d%s", data_array[i], (i == element_count - 1) ? "" : ", ");
    }
    printf(" ]\n");
}

void insert_at_index(int index, int value) {
    if (element_count >= MAX_CAPACITY) {
        printf("\nError: Array Overflow!");
        return;
    }
    /* Shift elements to the right */
    for (int i = element_count; i > index; i--) {
        data_array[i] = data_array[i - 1];
    }
    data_array[index] = value;
    element_count++;
}

void handle_insertion() {
    int mode, val, idx;
    printf("\n--- Insertion Interface ---");
    printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Custom Index");
    printf("\nChoice: ");
    scanf("%d", &mode);

    printf("Enter value to insert: ");
    scanf("%d", &val);

    switch (mode) {
        case 1: 
            insert_at_index(0, val); 
            break;
        case 2: 
            insert_at_index(element_count, val); 
            break;
        case 3:
            printf("Enter target index (0 to %d): ", element_count);
            scanf("%d", &idx);
            if (idx >= 0 && idx <= element_count) {
                insert_at_index(idx, val);
            } else {
                printf("\nError: Index %d is invalid.", idx);
            }
            break;
        default:
            printf("\nInvalid insertion mode.");
    }
}

void reverse_recursively(int start_idx, int end_idx) {
    if (start_idx >= end_idx) return;
    
    /* XOR swap for variety and logic */
    data_array[start_idx] ^= data_array[end_idx];
    data_array[end_idx]   ^= data_array[start_idx];
    data_array[start_idx] ^= data_array[end_idx];
    
    reverse_recursively(start_idx + 1, end_idx - 1);
}

void bubble_sort() {
    bool swapped;
    for (int i = 0; i < element_count - 1; i++) {
        swapped = false;
        for (int j = 0; j < element_count - i - 1; j++) {
            if (data_array[j] > data_array[j + 1]) {
                int temp = data_array[j];
                data_array[j] = data_array[j + 1];
                data_array[j + 1] = temp;
                swapped = true;
            }
        }
        /* Break if no two elements were swapped by inner loop */
        if (!swapped) break;
    }
}
