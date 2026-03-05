/**
 * @file stack_using_list.c
 * @brief Dynamic Stack implementation using a Singly Linked List.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

/* Pointer to the top of stack */
Node *stack_top = NULL;

/* Prototypes */
Node* create_node(int val);
void push_dynamic();
void pop_dynamic();
void display_dynamic();
void search_dynamic();

int main() {
    int choice;
    printf("--- Dynamic Stack (Refined) ---");
    
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Search\n5. Exit");
        printf("\nAction: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: push_dynamic(); break;
            case 2: pop_dynamic(); break;
            case 3: display_dynamic(); break;
            case 4: search_dynamic(); break;
            case 5: exit(0);
            default: printf("\nChoice Error!");
        }
    }
    return 0;
}

Node* create_node(int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("\nFatal: Memory Overflow!");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void push_dynamic() {
    int val;
    printf("Value to push: ");
    scanf("%d", &val);
    
    Node *newNode = create_node(val);
    newNode->next = stack_top;
    stack_top = newNode;
    printf("Value %d pushed into stack.", val);
}

void pop_dynamic() {
    if (stack_top == NULL) {
        printf("\nUnderflow: Stack is empty.");
        return;
    }
    Node *to_free = stack_top;
    int data = to_free->data;
    stack_top = stack_top->next;
    free(to_free);
    printf("Value %d popped from stack.", data);
}

void display_dynamic() {
    if (stack_top == NULL) {
        printf("\nStack status: Empty.");
        return;
    }
    Node *current = stack_top;
    printf("\nStack Structure (Vertical View):\n");
    while (current) {
        printf("| %3d |\n", current->data);
        printf("-------\n");
        current = current->next;
    }
}

void search_dynamic() {
    if (stack_top == NULL) return;
    int target, depth = 1;
    bool found = false;
    Node *current = stack_top;

    printf("Search for value: ");
    scanf("%d", &target);

    while (current) {
        if (current->data == target) {
            printf("\nFound %d at level %d from top.", target, depth);
            found = true;
        }
        current = current->next;
        depth++;
    }
    if (!found) printf("\nValue %d not in stack.", target);
}
