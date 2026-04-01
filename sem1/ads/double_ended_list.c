/**
 * @file double_ended_list.c
 * @brief Implementation of a Circular Singly Linked List for CET MCA.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head_node = NULL;

Node* create_node(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) exit(1);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insert_front();
void insert_back();
void delete_front();
void delete_back();
void display_circular();

int main() {
    int choice;
    head_node = create_node(0); /* Dummy head */

    while (1) {
        printf("\n--- Circular Linked List (Refined) ---");
        printf("\n1. Insert Front\n2. Insert Back\n3. Delete Front\n4. Delete Back\n5. Display\n6. Exit");
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_front(); break;
            case 2: insert_back(); break;
            case 3: delete_front(); break;
            case 4: delete_back(); break;
            case 5: display_circular(); break;
            case 6: exit(0);
            default: printf("\nInvalid Choice!");
        }
    }
    return 0;
}

void insert_front() {
    int val;
    printf("Value: "); scanf("%d", &val);
    Node *newNode = create_node(val);

    if (head_node->next == NULL) {
        head_node->next = newNode;
        newNode->next = newNode;
    } else {
        Node *last = head_node->next;
        while (last->next != head_node->next) last = last->next;
        newNode->next = head_node->next;
        head_node->next = newNode;
        last->next = newNode;
    }
}

void insert_back() {
    int val;
    printf("Value: "); scanf("%d", &val);
    Node *newNode = create_node(val);

    if (head_node->next == NULL) {
        head_node->next = newNode;
        newNode->next = newNode;
    } else {
        Node *last = head_node->next;
        while (last->next != head_node->next) last = last->next;
        last->next = newNode;
        newNode->next = head_node->next;
    }
}

void delete_front() {
    if (head_node->next == NULL) { printf("\nUnderflow!"); return; }
    Node *first = head_node->next;
    if (first->next == first) {
        head_node->next = NULL;
    } else {
        Node *last = head_node->next;
        while (last->next != head_node->next) last = last->next;
        head_node->next = first->next;
        last->next = head_node->next;
    }
    free(first);
}

void delete_back() {
    if (head_node->next == NULL) return;
    Node *current = head_node->next;
    if (current->next == current) {
        head_node->next = NULL;
        free(current);
    } else {
        Node *prev = NULL;
        while (current->next != head_node->next) {
            prev = current;
            current = current->next;
        }
        prev->next = head_node->next;
        free(current);
    }
}

void display_circular() {
    Node *current = head_node->next;
    if (!current) { printf("\nEmpty List."); return; }
    printf("\nCircular: ");
    do {
        printf("[%d] -> ", current->data);
        current = current->next;
    } while (current != head_node->next);
    printf("(START)\n");
}