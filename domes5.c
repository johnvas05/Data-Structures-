#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data < root->data) {
        // Insert in the left subtree
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        // Insert in the right subtree
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to search for a key in the binary tree
Node* binaryTreeSearch(Node* root, int key) {
    // Base case: if the root is NULL or the key is found
    if (root == NULL || root->data == key) {
        return root;
    }

    // If the key is smaller than the root's data, search in the left subtree
    if (key < root->data) {
        return binaryTreeSearch(root->left, key);
    }

    // If the key is greater, search in the right subtree
    return binaryTreeSearch(root->right, key);
}


// Main function
int main() {
    int key;
    Node* root = NULL;

    // Insert nodes into the binary tree
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("Choose a key to search:");
    scanf("%d", &key);
    Node* foundNode = binaryTreeSearch(root, key);
    if (foundNode != NULL) {
        printf("Key found: %d\n", foundNode->data); // prints the value stored in the node
    }else {
        printf("Key not found\n");
    }


    return 0;
}