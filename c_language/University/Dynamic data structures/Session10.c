#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
// Session 10 - Linked List

struct node{
    int data;
    struct node *next;
};


struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}




void printList(struct node *n){
    while (n != NULL){
        printf("%d\n", n->data);
        n = n->next;
    }
}



void insertAtFirst(struct node** head, int data) {
    struct node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void delete_list(struct node* p){
    if(p != NULL){
        delete_list(p->next);
        free(p);
    }
}

void insertAtLast(struct node** head, int data) {
    struct node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void delete_x(struct node** head, int x){
    struct node* temp = *head;
    struct node* prev = NULL;
    if (temp != NULL && temp->data == x){
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != x){
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL){
        printf("Element not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void insertAtPosition(struct node *p, int data, int position) {
    struct node* newNode = createNode(data);
    if (position == 0) {
        insertAtFirst(p,data);
        return;
    }
    struct node* temp = p;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void appending_two_linked_lists(struct node *n1, struct node *n2){
    struct node *temp = n1;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n2;
}

int main(){
    struct node *root, *p;
    root = malloc(sizeof(struct node));
    root->data = 10; // root --> 10 --> NULL
    root->next = malloc(sizeof(struct node)); // root --> 10 --> preallocated memory (but not initialized)

    p = root->next; // currently points to preallocated memory root --> 10 --> preallocated memory <-- p
    p->data = 20; // root --> 10 --> 20 --> NULL
    p->next = malloc(sizeof(struct node)); // root --> 10 --> 20 --> preallocated memory (but not initialized)

    p = p->next; // currently points to preallocated memory root --> 10 --> 20 --> preallocated memory <-- p
    p->data = 12; // root --> 10 --> 20 --> 12 --> NULL
    p->next = NULL; 

    p = root; // p points to root
    printList(p);
    insertAtLast(&p, 15);
    printf("\nAfter inserting 15 at index 1\n");
    printList(p);
    return 0;
}