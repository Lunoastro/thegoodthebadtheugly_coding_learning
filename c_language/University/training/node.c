#include <stdio.h>
#include <stdlib.h>

struct node{
    int data; // This part holds the data
    struct node *next; // This part shows the location of the next node
};

int main(){
    struct node *head = NULL; // This is the head of the linked list
    head = (struct node*)malloc(sizeof(struct node)); // Allocate memory for the head node
    if (head == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    head -> data = 1; // head node now holds 1
    head -> next = NULL; // The next node is NULL, indicating the end of the list
    printf("head node data: %d\n", head -> data); // Print the data of the head node
    return 0;
}