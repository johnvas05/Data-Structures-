#include <stdio.h>
#include <stdlib.h>

struct Tree {
    char data;
    struct Tree* left;
    struct Tree* right;
};

struct Tree* createNode(char data) {
    struct Tree* newNode = (struct Tree*)malloc(sizeof(struct Tree));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorderTraversal(struct Tree* root) {
    if (!root)
        return;
    inorderTraversal(root->left);
    printf("%c ", root->data);
    inorderTraversal(root->right);
}

int height(struct Tree* root) {
    if (!root)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void printLevel(struct Tree* root, int level) {
    if (!root)
        return;
    if (level == 1) {
        printf("%c ", root->data);
    } else if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void levelOrderTraversal(struct Tree* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printLevel(root, i);
    }
    printf("\n");
}

struct Tree* buildTree(char inorder[], char levelorder[], int inorderStart, int inorderEnd, int levelSize) {
    if (inorderStart > inorderEnd) {
        return NULL;
    }

    struct Tree* root = createNode(levelorder[0]);

    if (inorderStart == inorderEnd) {
        return root;
    }

    int inorderIndex = -1;
    for (int i = inorderStart; i <= inorderEnd; i++) {
        if (inorder[i] == root->data) {
            inorderIndex = i;
            break;
        }
    }

    char leftLevel[levelSize], rightLevel[levelSize];
    int leftCount = 0, rightCount = 0;

    for (int i = 1; i < levelSize; i++) {
        int found = 0;
        for (int j = inorderStart; j < inorderIndex; j++) {
            if (levelorder[i] == inorder[j]) {
                leftLevel[leftCount++] = levelorder[i];
                found = 1;
                break;
            }
        }
        if (!found) {
            for (int j = inorderIndex + 1; j <= inorderEnd; j++) {
                if (levelorder[i] == inorder[j]) {
                    rightLevel[rightCount++] = levelorder[i];
                    break;
                }
            }
        }
    }

    root->left = buildTree(inorder, leftLevel, inorderStart, inorderIndex - 1, leftCount);
    root->right = buildTree(inorder, rightLevel, inorderIndex + 1, inorderEnd, rightCount);

    return root;
}

int main() {
    char inorder[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char levelorder[] = {'A', 'B', 'C', 'D', 'E', 'F'};

    int inorderSize = sizeof(inorder) / sizeof(inorder[0]);
    int levelSize = sizeof(levelorder) / sizeof(levelorder[0]);

    struct Tree* root = buildTree(inorder, levelorder, 0, inorderSize - 1, levelSize);

    printf("Inorder Traversal of the reconstructed tree: ");
    inorderTraversal(root);
    printf("\n");

    printf("Level Order Traversal of the reconstructed tree: ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}