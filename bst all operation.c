#include <stdio.h>
#include <stdlib.h>

// Definition of a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in a BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root; // If the key is found or the tree is empty
    }

    if (key < root->data) {
        return search(root->left, key); // Search in the left subtree
    }
    
    return search(root->right, key); // Search in the right subtree
}

int main() {
    struct Node* root = NULL;
    int n, value, key;

    // Get the number of nodes from the user
    printf("Enter the number of elements to insert into the BST: ");
    scanf("%d", &n);

    // Get the values to insert into the BST
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Get the key to search for
    printf("Enter the element to search in the BST: ");
    scanf("%d", &key);

    // Search for the key in the BST
    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("Element %d found in the BST.\n", result->data);
    } else {
        printf("Element %d not found in the BST.\n", key);
    }

    return 0;
}
