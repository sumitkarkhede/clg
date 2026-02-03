//Implement the following operations:
//1. Insert a node at position k
//2. Delete the node at position k

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Insert at position k
Node* insertAtPosition(Node* head, int value, int k) {
    if (k < 0) return head;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    // Insert at head
    if (k == 0) {
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    for (int i = 0; temp != NULL && i < k - 1; i++) {
        temp = temp->next;
    }

    // Invalid position
    if (temp == NULL) {
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Delete node at position k
Node* deleteAtPosition(Node* head, int k) {
    if (head == NULL || k < 0) return head;

    Node* temp = head;

    // Delete head
    if (k == 0) {
        head = temp->next;
        free(temp);
        return head;
    }

    for (int i = 0; temp != NULL && i < k - 1; i++) {
        temp = temp->next;
    }

    // Invalid position
    if (temp == NULL || temp->next == NULL)
        return head;

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);

    return head;
}

// Display list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (head != NULL) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Free entire list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    // Creating list: 10 -> 20 -> 30 -> 40
    head = insertAtPosition(head, 10, 0);
    head = insertAtPosition(head, 20, 1);
    head = insertAtPosition(head, 30, 2);
    head = insertAtPosition(head, 40, 3);

    printf("Initial List:\n");
    displayList(head);

    // Insert 25 at position 2
    head = insertAtPosition(head, 25, 2);
    printf("After inserting 25 at position 2:\n");
    displayList(head);

    // Delete node at position 4
    head = deleteAtPosition(head, 4);
    printf("After deleting node at position 4:\n");
    displayList(head);

    freeList(head);
    return 0;
}
