#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node  {
    int data;
    struct node* next;
} Node ;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node** top, int data) {
    Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed to stack\n", data);
}

int isEmpty(Node* top) {
    return top == NULL;
}

int pop(Node** top) {
    if (isEmpty(*top)) {
        printf("Stack underflow\n");
        return -1; // Indicate stack is empty
    }
    Node* temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

int peek(Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return -1; // Indicate stack is empty
    }
    return top->data;
}

bool isPalindrome(Node* stack) {
    // Count the number of elements in the stack
    int count = 0;
    Node* temp = stack;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Store the elements of the stack in an array
    int* elements = (int*)malloc(count * sizeof(int));
    if (!elements) {
        printf("Memory allocation failed\n");
        return false;
    }

    temp = stack;
    for (int i = 0; i < count; i++) {
        elements[i] = temp->data;
        temp = temp->next;
    }

    // Check if the array is a palindrome
    bool isPalindrome = true;
    for (int i = 0; i < count / 2; i++) {
        if (elements[i] != elements[count - i - 1]) {
            isPalindrome = false;
            break;
        }
    }

    free(elements); // Free the allocated memory
    return isPalindrome;
}

int main() {
    Node* stack = NULL; // Initialize the stack

    // Fill the stack with example values
    push(&stack, 1);
    push(&stack, 1);
    push(&stack, 3);
    push(&stack, 2);
    push(&stack, 1);
    push(&stack, 1);
    if (isPalindrome(stack)) {
        printf("The stack contains a palindrome\n");
    } else {
        printf("The stack does not contain a palindrome\n");
    }

    return 0;
}