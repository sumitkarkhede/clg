// DOUBLY LINKED LIST (ADVANCED)
// Operations to be Implemented
// 1. Reverse a doubly linked list.
// 2. Find the pair of nodes whose sum equals a given value (two-pointer technique)
// 3. Rotate the doubly linked list by k nodes
// 4. Delete all nodes having duplicate values (unsorted list)
// 5. Find the maximum sum sublist in a doubly linked list
// 6. Check whether the doubly linked list is a palindrome
// 7. Merge two sorted doubly linked lists
// 8. Swap nodes (not data) at two given positions
// 9. Clone a doubly linked list with random pointer

#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Insert at end
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Print list
void printList(Node* head){
    while (head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}