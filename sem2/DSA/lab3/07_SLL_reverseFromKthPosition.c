// Reverse the list in groups of size k.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Insert at end (helper function)
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (!head) return newNode;

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Reverse linked list in groups of k (ITERATIVE, O(1) space)
Node* reverseInGroups(Node* head, int k) {
    if (!head || k <= 1) return head;

    Node *curr = head, *prevTail = NULL, *newHead = NULL;

    while (curr) {
        Node* groupHead = curr;
        Node* prev = NULL;
        int count = 0;

        // Check if at least k nodes remain
        Node* temp = curr;
        for (int i = 0; i < k; i++) {
            if (!temp) {
                // Not enough nodes, attach remaining part and stop
                if (prevTail)
                    prevTail->next = curr;
                return newHead ? newHead : head;
            }
            temp = temp->next;
        }

        // Reverse k nodes
        while (curr && count < k) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // First reversed group becomes new head
        if (!newHead)
            newHead = prev;

        // Connect previous group's tail to current reversed head
        if (prevTail)
            prevTail->next = prev;

        // groupHead is now the tail of reversed group
        prevTail = groupHead;
    }

    return newHead;
}

// Display list
void displayList(Node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Free memory
void freeList(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    // Create list: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8
    for (int i = 1; i <= 8; i++)
        head = insertAtEnd(head, i);

    int k = 3;

    printf("Original List:\n");
    displayList(head);

    head = reverseInGroups(head, k);

    printf("After reversing in groups of %d:\n", k);
    displayList(head);

    freeList(head);
    return 0;
}
