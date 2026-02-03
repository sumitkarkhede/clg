// Implement insertion at the end of the list such that each insertion occurs in O(1) time

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Insert at end in O(1)
void insertAtEnd(Node** head, Node** tail, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    // Case 1: Empty list
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
        return;
    }

    // Case 2: Non-empty list
    (*tail)->next = newNode;
    *tail = newNode;
}

// Display list
void displayList(Node* head) {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL, *tail = NULL;

    insertAtEnd(&head, &tail, 10);
    insertAtEnd(&head, &tail, 20);
    insertAtEnd(&head, &tail, 30);
    insertAtEnd(&head, &tail, 40);

    displayList(head);

    return 0;
}
