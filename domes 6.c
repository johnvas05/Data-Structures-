#include <stdio.h>
#include <stdlib.h>

struct Tree {
    int data;
    struct Tree* left;
    struct Tree* right;
};

struct Tree* createNode(int data) {
    struct Tree* newNode = (struct Tree*)malloc(sizeof(struct Tree));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int height(struct Tree* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    
    struct Tree* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Tree height: %d\n", height(root));
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
