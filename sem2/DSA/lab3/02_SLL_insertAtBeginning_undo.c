//Insert a node at the beginning of the list with an undo operation that reverts the list to its previous state.

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Insert at front with undo tracking
Node* insertFront(Node* head, int value, Node** prevHead, Node** lastInserted) {
    *prevHead = head;  // Save previous state

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;

    *lastInserted = newNode;  // Track inserted node
    return newNode;
}

// Undo last insertFront
Node* undoInsert(Node* head, Node* prevHead, Node* lastInserted) {
    if (lastInserted == NULL) {
        printf("Nothing to undo.\n");
        return head;
    }

    free(lastInserted);  // Remove inserted node
    return prevHead;     // Restore previous head
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
    Node* head = NULL;
    Node* prevHead = NULL;      // Stores previous state
    Node* lastInserted = NULL;  // Stores last inserted node

    head = insertFront(head, 10, &prevHead, &lastInserted);
    head = insertFront(head, 20, &prevHead, &lastInserted);

    printf("After insertions:\n");
    displayList(head);

    head = undoInsert(head, prevHead, lastInserted);
    lastInserted = NULL; // Only one-level undo allowed

    printf("After undo:\n");
    displayList(head);

    return 0;
}
