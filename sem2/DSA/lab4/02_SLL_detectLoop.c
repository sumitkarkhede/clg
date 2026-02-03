//2. Detect a loop in a singly linked list.


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Insert at end (helper)
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

// Detect and remove cycle
void detectAndRemoveCycle(Node* head) {
    if (!head) return;

    Node *slow = head, *fast = head;
    int cycleExists = 0;

    // Step 1: Detect cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            cycleExists = 1;
            break;
        }
    }

    if (!cycleExists) {
        printf("No cycle detected.\n");
        return;
    }

    printf("Cycle detected!\n");

    // Step 2: Find start of cycle
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    Node* cycleStart = slow;
    printf("Cycle starts at node with value: %d\n", cycleStart->data);

    // Step 3: Find last node in cycle and remove it
    Node* temp = cycleStart;
    while (temp->next != cycleStart) {
        temp = temp->next;
    }

    temp->next = NULL; // Break cycle
    printf("Cycle removed successfully.\n");
}

// Display list safely (limit to avoid infinite loop)
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

    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    // Create a cycle manually: last node -> node with value 3
    Node* temp = head;
    Node* join = NULL;
    while (temp->next) {
        if (temp->data == 3) join = temp;
        temp = temp->next;
    }
    temp->next = join;  // Cycle created

    detectAndRemoveCycle(head);

    printf("List after cycle removal:\n");
    displayList(head);

    freeList(head);
    return 0;
}
