/*
arguments passed in procedure calls are copied 
change an argument in the procedure this has a load effect only 
3 solutions to make alawys persist:

- guard (1st dummy element that never changes )
- extra pointer that does not change 
- return the modified object and replace the original object 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
struct node {
    int value;
    struct node* next;
};
struct node** lst1;
struct node** lst2;

struct node* createNode(int value) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

struct node** init(){
    struct node** l;
    l = (struct node**)malloc(sizeof(struct node*)); 
    // allocate memory for the pointer to the list i.e node* holds the address of the first node so we need to allocate memory for the pointer address
    *l = NULL;
    return l;
}




struct node* insert(struct node* p, int toInsert)
// p makes a copy of the inserted parameter node
{
    struct node* q;
    if (p == NULL || p->value > toInsert) {
        q = malloc(sizeof(struct node));
        q -> value = toInsert;
        q -> next = p;
        return q;
    } 
    p -> next = insert(p->next, toInsert);

    return p;
}

int main(){return -1;}
