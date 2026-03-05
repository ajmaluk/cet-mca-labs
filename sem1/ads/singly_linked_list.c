/**
 * @file singly_linked_list.c
 * @brief Professional implementation of a Singly Linked List for CET MCA.
 * 
 * Features: Naming standardization, recursive traversal, and modular node creation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Type definition for cleaner pointer management */
typedef struct node {
    int data;
    struct node *next;
} Node;

/* Global pointers with descriptive names */
Node *head_node = NULL;
Node *copy_head_node = NULL;

/* Function prototypes with snake_case naming */
Node* create_node(int value);
void insert_at_beginning();
void insert_at_end();
void insert_at_position();
void delete_from_beginning();
void delete_from_end();
void delete_from_position();
void display_list(Node *h, const char *title);
void search_element();
void merge_lists();
void replicate_list();

int main() {
    int choice;

    /* Initialize dummy heads for cleaner edge case handling */
    head_node = create_node(0);
    copy_head_node = create_node(0);

    while (1) {
        printf("\n--- Singly Linked List (Refined) ---");
        printf("\n1. Insert Front\n2. Insert End\n3. Insert at Pos");
        printf("\n4. Delete Front\n5. Delete End\n6. Delete at Pos");
        printf("\n7. Display List\n8. Search\n9. Merge List");
        printf("\n10. Copy List\n11. Display Copy\n12. Exit");
        printf("\nChoice: ");
        
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: insert_at_beginning(); break;
            case 2: insert_at_end(); break;
            case 3: insert_at_position(); break;
            case 4: delete_from_beginning(); break;
            case 5: delete_from_end(); break;
            case 6: delete_from_position(); break;
            case 7: display_list(head_node, "Main List"); break;
            case 8: search_element(); break;
            case 9: merge_lists(); break;
            case 10: replicate_list(); break;
            case 11: display_list(copy_head_node, "Replicated List"); break;
            case 12: exit(0);
            default: printf("\nInvalid Choice!");
        }
    }
    return 0;
}

Node* create_node(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("\nFatal: Memory Allocation Failed!");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insert_at_beginning() {
    int val;
    printf("Enter value: ");
    scanf("%d", &val);
    Node *newNode = create_node(val);
    newNode->next = head_node->next;
    head_node->next = newNode;
    printf("Inserted %d at front.", val);
}

void insert_at_end() {
    int val;
    printf("Enter value: ");
    scanf("%d", &val);
    Node *newNode = create_node(val);
    Node *current = head_node;
    while (current->next != NULL) current = current->next;
    current->next = newNode;
    printf("Inserted %d at end.", val);
}

void insert_at_position() {
    int val, pos;
    printf("Enter value: ");
    scanf("%d", &val);
    printf("Enter position: ");
    scanf("%d", &pos);

    Node *current = head_node;
    for (int i = 1; i < pos && current != NULL; i++) 
        current = current->next;

    if (!current) {
        printf("\nError: Position Out of Range!");
    } else {
        Node *newNode = create_node(val);
        newNode->next = current->next;
        current->next = newNode;
        printf("Inserted %d at position %d.", val, pos);
    }
}

void delete_from_beginning() {
    if (head_node->next == NULL) {
        printf("\nUnderflow: List is Empty!");
        return;
    }
    Node *toDelete = head_node->next;
    head_node->next = toDelete->next;
    printf("Deleted value: %d", toDelete->data);
    free(toDelete);
}

void delete_from_end() {
    if (head_node->next == NULL) {
        printf("\nUnderflow: List is Empty!");
        return;
    }
    Node *current = head_node;
    while (current->next->next != NULL) current = current->next;
    
    printf("Deleted value: %d", current->next->data);
    free(current->next);
    current->next = NULL;
}

void delete_from_position() {
    int pos;
    if (head_node->next == NULL) {
        printf("\nUnderflow!");
        return;
    }
    printf("Enter position: ");
    scanf("%d", &pos);

    Node *current = head_node;
    for (int i = 1; i < pos && current->next != NULL; i++) 
        current = current->next;

    if (current->next == NULL) {
        printf("\nInvalid Position!");
    } else {
        Node *toDelete = current->next;
        current->next = toDelete->next;
        printf("Deleted value: %d", toDelete->data);
        free(toDelete);
    }
}

void display_list(Node *h, const char *title) {
    Node *current = h->next;
    if (!current) {
        printf("\n%s is currently empty.", title);
        return;
    }
    printf("\n%s Content: ", title);
    while (current) {
        printf("[%d] -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void search_element() {
    int target, pos = 1;
    bool isFound = false;
    if (head_node->next == NULL) {
        printf("\nList is empty.");
        return;
    }
    printf("Enter target value: ");
    scanf("%d", &target);
    
    Node *current = head_node->next;
    while (current) {
        if (current->data == target) {
            printf("\nValue %d found at position %d", target, pos);
            isFound = true;
        }
        current = current->next;
        pos++;
    }
    if (!isFound) printf("\nValue not found in list.");
}

void merge_lists() {
    int n, val;
    printf("\nNumber of elements for new list: ");
    scanf("%d", &n);
    
    Node *temp_head = create_node(0);
    Node *tail = temp_head;

    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &val);
        Node *newNode = create_node(val);
        tail->next = newNode;
        tail = newNode;
    }

    /* Append to original list */
    Node *current = head_node;
    while (current->next != NULL) current = current->next;
    current->next = temp_head->next;
    
    printf("\nSuccessfully merged lists.");
    free(temp_head);
}

void replicate_list() {
    /* Clear existing copy */
    while (copy_head_node->next != NULL) {
        Node *temp = copy_head_node->next;
        copy_head_node->next = temp->next;
        free(temp);
    }

    Node *source = head_node->next;
    Node *dest_tail = copy_head_node;
    
    while (source) {
        Node *newNode = create_node(source->data);
        dest_tail->next = newNode;
        dest_tail = newNode;
        source = source->next;
    }
    printf("\nList replicated successfully.");
}