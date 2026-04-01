/**
 * @file bst.c
 * @brief Binary Search Tree (BST) implementation for CET MCA.
 * 
 * Includes insertion, deletion (3 cases), and recursive traversals.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} TreeNode;

/* Global root pointer */
TreeNode *root_node = NULL;

/* Prototypes */
TreeNode* create_tree_node(int val);
TreeNode* insert_recursive(TreeNode* root, int val);
TreeNode* delete_recursive(TreeNode* root, int val);
TreeNode* find_min_node(TreeNode* node);
void traverse_pre_order(TreeNode* root);
void traverse_in_order(TreeNode* root);
void traverse_post_order(TreeNode* root);
void handle_traversal_menu();

int main() {
    int choice, val;
    printf("--- Binary Search Tree (BST) Hub ---");
    
    while (1) {
        printf("\n\n1. Insert Value\n2. Delete Value\n3. View Traversal\n4. Exit");
        printf("\nAction: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root_node = insert_recursive(root_node, val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                root_node = delete_recursive(root_node, val);
                break;
            case 3:
                handle_traversal_menu();
                break;
            case 4:
                exit(0);
            default:
                printf("\nSelection Error!");
        }
    }
    return 0;
}

TreeNode* create_tree_node(int val) {
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) return NULL;
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* insert_recursive(TreeNode* root, int val) {
    if (root == NULL) return create_tree_node(val);
    
    if (val < root->data)
        root->left = insert_recursive(root->left, val);
    else if (val > root->data)
        root->right = insert_recursive(root->right, val);
    else
        printf("\nDuplicate value %d ignored.", val);
        
    return root;
}

TreeNode* find_min_node(TreeNode* node) {
    TreeNode *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

TreeNode* delete_recursive(TreeNode* root, int val) {
    if (root == NULL) {
        printf("\nValue %d not found.", val);
        return root;
    }

    if (val < root->data)
        root->left = delete_recursive(root->left, val);
    else if (val > root->data)
        root->right = delete_recursive(root->right, val);
    else {
        /* Node with only one child or no child */
        if (root->left == NULL) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        /* Node with two children: Get the inorder successor */
        TreeNode *temp = find_min_node(root->right);
        root->data = temp->data;
        root->right = delete_recursive(root->right, temp->data);
    }
    return root;
}

void traverse_pre_order(TreeNode* root) {
    if (root) {
        printf("%d ", root->data);
        traverse_pre_order(root->left);
        traverse_pre_order(root->right);
    }
}

void traverse_in_order(TreeNode* root) {
    if (root) {
        traverse_in_order(root->left);
        printf("%d ", root->data);
        traverse_in_order(root->right);
    }
}

void traverse_post_order(TreeNode* root) {
    if (root) {
        traverse_post_order(root->left);
        traverse_post_order(root->right);
        printf("%d ", root->data);
    }
}

void handle_traversal_menu() {
    int mode;
    if (!root_node) { printf("\nTree is empty."); return; }
    printf("\nOrder: 1.Pre  2.In  3.Post: ");
    scanf("%d", &mode);
    printf("Result: ");
    if (mode == 1) traverse_pre_order(root_node);
    else if (mode == 2) traverse_in_order(root_node);
    else if (mode == 3) traverse_post_order(root_node);
    printf("\n");
}
