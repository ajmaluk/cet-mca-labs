/**
 * @file circular_queue.c
 * @brief Circular Queue implementation to prevent memory wastage in array-based queues.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CQ_MAX 100

/* State */
int cq_data[CQ_MAX];
int head = -1; /* Same as front */
int tail = -1; /* Same as rear */
int q_size = CQ_MAX;

/* Operations */
void enqueue_circular();
void dequeue_circular();
void display_circular_status();
void search_circular_element();

int main() {
    int choice;
    printf("Configuration: Set Circular Queue size: ");
    scanf("%d", &q_size);
    if (q_size > CQ_MAX) q_size = CQ_MAX;

    while (1) {
        printf("\n--- Circular Queue Manager ---");
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Search\n5. Exit");
        printf("\nPrompt: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue_circular(); break;
            case 2: dequeue_circular(); break;
            case 3: display_circular_status(); break;
            case 4: search_circular_element(); break;
            case 5: exit(0);
            default: printf("\nInput Error: Choice not recognized.");
        }
    }
    return 0;
}

void enqueue_circular() {
    int val;
    /* Check if full: (tail + 1) % size == head */
    if ((tail + 1) % q_size == head) {
        printf("\nOverflow: Circular buffer is saturated.");
        return;
    }

    printf("Value to add: ");
    scanf("%d", &val);

    if (head == -1) {
        head = tail = 0;
    } else {
        tail = (tail + 1) % q_size;
    }

    cq_data[tail] = val;
    printf("Added %d to position %d.", val, tail);
}

void dequeue_circular() {
    if (head == -1) {
        printf("\nUnderflow: Circular buffer is empty.");
        return;
    }

    printf("\nPopped %d from position %d.", cq_data[head], head);

    if (head == tail) {
        /* Reset when queue becomes empty */
        head = tail = -1;
    } else {
        head = (head + 1) % q_size;
    }
}

void display_circular_status() {
    if (head == -1) {
        printf("\nStatus: Buffer empty.");
        return;
    }

    printf("\nCycle Content: ");
    int i = head;
    while (true) {
        printf("[%d] ", cq_data[i]);
        if (i == tail) break;
        i = (i + 1) % q_size;
    }
    printf("\n(Head: %d, Tail: %d)\n", head, tail);
}

void search_circular_element() {
    if (head == -1) {
        printf("\nSearch failed: Buffer empty.");
        return;
    }
    
    int target, i = head;
    bool found = false;
    printf("Target search value: ");
    scanf("%d", &target);

    while (true) {
        if (cq_data[i] == target) {
            printf("\nFound %d at physical index %d", target, i);
            found = true;
        }
        if (i == tail) break;
        i = (i + 1) % q_size;
    }

    if (!found) printf("\nValue %d not found in circular cycle.", target);
}