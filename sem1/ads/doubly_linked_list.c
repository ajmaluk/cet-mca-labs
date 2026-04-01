/**
 * @file doubly_linked_list.c
 * @brief Professional implementation of a Doubly Linked List for CET MCA.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} Node;

Node *head_node = NULL;

Node* create_node(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) exit(1);
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert_front();
void insert_back();
void insert_at_pos();
void delete_front();
void delete_back();
void delete_at_pos();
void display_forward();
void display_backward();

int main() {
    int choice;
    head_node = create_node(0); /* Dummy head */

    while (1) {
        printf("\n--- Doubly Linked List (Refined) ---");
        printf("\n1. Insert Front\n2. Insert Back\n3. Insert at Pos");
        printf("\n4. Delete Front\n5. Delete Back\n6. Delete at Pos");
        printf("\n7. Display Forward\n8. Display Backward\n9. Exit");
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_front(); break;
            case 2: insert_back(); break;
            case 3: insert_at_pos(); break;
            case 4: delete_front(); break;
            case 5: delete_back(); break;
            case 6: delete_at_pos(); break;
            case 7: display_forward(); break;
            case 8: display_backward(); break;
            case 9: exit(0);
            default: printf("\nInvalid Choice!");
        }
    }
    return 0;
}

void insert_front() {
    int val;
    printf("Enter value: ");
    scanf("%d", &val);
    Node *newNode = create_node(val);
    
    newNode->next = head_node->next;
    newNode->prev = head_node;
    if (head_node->next) head_node->next->prev = newNode;
    head_node->next = newNode;
}

void insert_back() {
    int val;
    printf("Enter value: ");
    scanf("%d", &val);
    Node *newNode = create_node(val);
    Node *current = head_node;
    while (current->next) current = current->next;
    
    current->next = newNode;
    newNode->prev = current;
}

void insert_at_pos() {
    int val, pos;
    printf("Value: "); scanf("%d", &val);
    printf("Position: "); scanf("%d", &pos);
    
    Node *current = head_node;
    for (int i = 1; i < pos && current; i++) current = current->next;
    
    if (!current) {
        printf("\nPosition invalid!");
    } else {
        Node *newNode = create_node(val);
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next) current->next->prev = newNode;
        current->next = newNode;
    }
}

void delete_front() {
    if (!head_node->next) { printf("\nUnderflow!"); return; }
    Node *toDelete = head_node->next;
    head_node->next = toDelete->next;
    if (toDelete->next) toDelete->next->prev = head_node;
    free(toDelete);
}

void delete_back() {
    if (!head_node->next) { printf("\nUnderflow!"); return; }
    Node *current = head_node->next;
    while (current->next) current = current->next;
    
    current->prev->next = NULL;
    free(current);
}

void delete_at_pos() {
    int pos;
    if (!head_node->next) return;
    printf("Position: "); scanf("%d", &pos);
    
    Node *current = head_node->next;
    for (int i = 1; i < pos && current; i++) current = current->next;
    
    if (!current) {
        printf("\nInvalid Position!");
    } else {
        current->prev->next = current->next;
        if (current->next) current->next->prev = current->prev;
        free(current);
    }
}

void display_forward() {
    Node *current = head_node->next;
    printf("\nForward: ");
    while (current) {
        printf("[%d] <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void display_backward() {
    Node *current = head_node->next;
    if (!current) return;
    while (current->next) current = current->next;
    
    printf("\nBackward: ");
    while (current != head_node) {
        printf("[%d] <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}