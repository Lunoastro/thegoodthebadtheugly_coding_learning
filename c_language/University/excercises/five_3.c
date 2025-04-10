// count the occurrences of an integer x in a linked list.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void printList(struct node *n){
    while (n != NULL){
        printf("%d\n", n->data);
        n = n->next;
    }
}

int count(struct node *n, int x){
    int count = 0;
    while (n != NULL){
        if (n->data == x){
            count++;
        }
        n = n->next;
    }
    return count;
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
    printf("Number of 10s: %d\n", count(p, 10));

    return 0;
}