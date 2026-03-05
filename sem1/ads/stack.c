/**
 * @file stack.c
 * @brief Standard Stack (LIFO) implementation using a static array.
 */

#include <stdio.h>
#include <stdbool.h>

#define STACK_MAX 100

/* Stack state encapsulation */
int stack_data[STACK_MAX];
int top_idx = -1;

/* Operations */
bool is_full();
bool is_empty();
void push_element(int val);
int pop_element();
void display_stack_status();

int main() {
    int choice, val;

    while (1) {
        printf("\n--- Stack Dashboard (Array-Based) ---");
        printf("\n1. Push\n2. Pop\n3. View Stack\n4. Exit");
        printf("\nAction: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push_element(val);
                break;
            case 2:
                val = pop_element();
                if (val != -1) printf("Successful Pop: %d", val);
                break;
            case 3:
                display_stack_status();
                break;
            case 4:
                return 0;
            default:
                printf("\nUnrecognized command.");
        }
    }
}

bool is_full() {
    return top_idx == STACK_MAX - 1;
}

bool is_empty() {
    return top_idx == -1;
}

void push_element(int val) {
    if (is_full()) {
        printf("\nOverflow: Stack capacity reached!");
        return;
    }
    stack_data[++top_idx] = val;
    printf("\nPushed %d onto the stack.", val);
}

int pop_element() {
    if (is_empty()) {
        printf("\nUnderflow: Stack is empty.");
        return -1;
    }
    return stack_data[top_idx--];
}

void display_stack_status() {
    if (is_empty()) {
        printf("\nStack is currently empty.");
        return;
    }
    printf("\nStack Content (Top to Bottom):\n");
    for (int i = top_idx; i >= 0; i--) {
        printf("| %3d |\n", stack_data[i]);
        printf("-------\n");
    }
}
