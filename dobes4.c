#include <stdio.h>
#include <stdlib.h>

typedef struct node  {
    int data;
    struct node* next;
} Node ;

Node* recursive_search(Node *head, int key) {
    if (head == NULL){
        return NULL;
    } else if (head->data == key){
        return head;
    } else {
        return recursive_search(head->next, key);
    }
}


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    int key;
    printf("Enter a key: ");
    scanf("%d", &key);


    Node* result;
    result = recursive_search( head, key);

    if (result != NULL) {
        printf("Found node with data: %d\n", result->data);
    } else {
        printf("Key not found in the list.\n");
    }

    return 0;
}