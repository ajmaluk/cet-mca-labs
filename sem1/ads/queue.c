/**
 * @file queue.c
 * @brief Standard Linear Queue (FIFO) implementation for CET MCA.
 */

#include <stdio.h>
#include <stdbool.h>

#define QUEUE_MAX 100

/* Queue state */
int queue_data[QUEUE_MAX];
int front_idx = -1;
int rear_idx = -1;
int current_capacity = QUEUE_MAX;

/* Prototypes */
void add_to_queue();
void remove_from_queue();
void display_queue();
void find_in_queue();

int main() {
    int choice;
    printf("Initialize Queue size (max %d): ", QUEUE_MAX);
    scanf("%d", &current_capacity);
    if (current_capacity > QUEUE_MAX) current_capacity = QUEUE_MAX;

    while (1) {
        printf("\n--- Linear Queue Dashboard ---");
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Search\n5. Exit");
        printf("\nCommand: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_to_queue(); break;
            case 2: remove_from_queue(); break;
            case 3: display_queue(); break;
            case 4: find_in_queue(); break;
            case 5: return 0;
            default: printf("\nInvalid Selection.");
        }
    }
}

void add_to_queue() {
    int val;
    if (rear_idx == current_capacity - 1) {
        printf("\nQueue Overflow: Capacity full.");
        return;
    }
    printf("Value to enqueue: ");
    scanf("%d", &val);
    
    if (front_idx == -1) front_idx = 0;
    queue_data[++rear_idx] = val;
    printf("Queued value: %d", val);
}

void remove_from_queue() {
    if (front_idx == -1) {
        printf("\nQueue Underflow: No data available.");
        return;
    }
    printf("Dequeued value: %d", queue_data[front_idx]);
    
    if (front_idx == rear_idx) {
        /* Reset state when last element is removed */
        front_idx = rear_idx = -1;
    } else {
        front_idx++;
    }
}

void display_queue() {
    if (front_idx == -1) {
        printf("\n[ [Queue is Empty] ]");
        return;
    }
    printf("\nQueue visualization: [ ");
    for (int i = front_idx; i <= rear_idx; i++) {
        printf("%d%s", queue_data[i], (i == rear_idx) ? "" : " | ");
    }
    printf(" ]");
}

void find_in_queue() {
    int target;
    bool isFound = false;
    if (front_idx == -1) { printf("\nQueue is empty."); return; }
    
    printf("Search for: ");
    scanf("%d", &target);
    
    for (int i = front_idx; i <= rear_idx; i++) {
        if (queue_data[i] == target) {
            printf("\nValue %d found at index %d", target, i);
            isFound = true;
        }
    }
    if (!isFound) printf("\nValue %d not present.", target);
}