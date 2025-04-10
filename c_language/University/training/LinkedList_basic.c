#include <stdio.h>
#include <stdlib.h>

/*
* THIS type of linked list will not know what the node is before them
* they will only know the location of the subsequent node
* This is a singly linked list
*/
struct node{
    int data; // This part holds the data
    struct node *next; // This part shows the location of the next node
};

void freeLinkedList(struct node *head) {
    struct node *current = head; // Start from the head
    struct node *next_node; // Pointer to hold the next node

    while (current != NULL) { // Traverse the linked list
        next_node = current->next; // Store the next node
        free(current); // Free the current node
        current = next_node; // Move to the next node
    }
}

void printLinkedList(struct node *head) {
    struct node *current = head; // Start from the head
    while (current != NULL) { // Traverse the linked list
        printf("%d ", current->data); // Print the data of the current node
        current = current->next; // Move to the next node
    }
    printf("\n");
}

int main(){
    struct node *head = NULL; // This is the head of the linked list    
    head = (struct node*)malloc(sizeof(struct node)); // Allocate memory for the head node
    if (head == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    /*
    * THIS FOR LOOP CREATES 5 NODES 
    * AND LINKS THEM TOGETHER
    */
    for(int i = 0; i < 5; i++){
        struct node *new_node = (struct node*)malloc(sizeof(struct node)); // Allocate memory for a new node
        if (new_node == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        new_node->data = i + 1; // Assign data to the new node
        new_node->next = head; // Link the new node to the previous head
        head = new_node; // Update head to point to the new node
    }

    printLinkedList(head); // Print the linked list

    /*
    * THIS WHILE LOOP FREES THE MEMORY
    * ALLOCATED FOR EACH NODE IN THE LINKED LIST
    */
    // Free the allocated memory
    freeLinkedList(head);
    // Set head to NULL to avoid dangling pointer
    head = NULL;

    return 0;
}
