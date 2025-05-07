#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* create_node(int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void insert_at_end(struct node** head, int value) {
    struct node* new_node = create_node(value);

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

void mergeTwoLists(struct node* head1, struct node* head2) {
    if (head1 == NULL) {
        return;
    }

    struct node* current = head1;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = head2;
}

void sortlist(struct node** head1){
    struct node* current = *head1;
    struct node* temp = *head1;
    
    while (current->next != NULL){
        temp = current->next;
        while (temp != NULL){

            if(temp->data < current->data){
                int t = temp->data;
                temp->data = current->data;
                current->data = t;
            }
            temp=temp->next;
        }
        current = current->next;
    }
}

void print_list(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* list1 = NULL;
    struct node* list2 = NULL;

    insert_at_end(&list1, 1);
    insert_at_end(&list1, 2);
    insert_at_end(&list1, 4);

    insert_at_end(&list2, 3);
    insert_at_end(&list2, 9);
    insert_at_end(&list2, 5);

    printf("List 1: ");
    print_list(list1);

    printf("List 2: ");
    print_list(list2);

    mergeTwoLists(list1, list2);
    sortlist(&list1);

    printf("Merged List: ");
    print_list(list1);

    return 0;
}
