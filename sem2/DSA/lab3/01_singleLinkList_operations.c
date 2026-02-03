/*Design a singly linked list Abstract Data Type (ADT) that supports the following operations:
1. Insert at head
2. Insert at tail
3. Delete by value (first occurrence)
4. Delete by position (0-based indexing)
5. Search for a value
6. Reverse the list
7. Detect cycle (if any)
8. Display list*/

#include <stdio.h>
#include <stdlib.h>

// Node Structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//////////////////////////////////////////////////////////////
// Function Prototypes

Node* insertAtHead(Node* head, int value);
Node* insertAtTail(Node* head, int value);
Node* deleteByValue(Node* head, int value);
Node* deleteByPosition(Node* head, int pos);
int search(Node* head, int value);
Node* reverseList(Node* head);
int detectCycle(Node* head);
void displayList(Node* head);
void freeList(Node* head);

//////////////////////////////////////////////////////////////

//Insert at Head
Node* insertAtHead(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;

}

// Insert at Tail
Node* insertAtTail(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value; 
    newNode->next = NULL;

    if (head == NULL) return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Delete by Value (first occurrence)
Node* deleteByValue(Node* head, int value) {
    if (head == NULL) return head;

    Node *temp = head, *prev = NULL;

    if (temp->data == value) {
        head = temp->next;
        free(temp);
        return head;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return head; // Not found

    prev->next = temp->next;
    free(temp);
    return head;
}

// Delete by Position (0-based)
Node* deleteByPosition(Node* head, int pos) {
    if (head == NULL || pos < 0) return head;

    Node *temp = head;

    if (pos == 0) {
        head = temp->next;
        free(temp);
        return head;
    }

    for (int i = 0; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) return head;

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);

    return head;
}

// Search
int search(Node* head, int value) {
    int pos = 0;
    while (head != NULL) {
        if (head->data == value)
            return pos;
        head = head->next;
        pos++;
    }
    return -1; // Not found
}

//  Reverse List
Node* reverseList(Node* head) {
    Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Detect Cycle (Floyd’s Algorithm)
int detectCycle(Node* head) {
    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1; // Cycle exists
    }
    return 0;
}

//  Display List
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

//  Free Entire List
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

//////////////////////////////////////////////////////////////
// Main Function (Demo)
int main() {
    Node* head = NULL;

    head = insertAtTail(head, 10);
    head = insertAtTail(head, 20);
    head = insertAtTail(head, 30);

    printf("Original List:\n");
    displayList(head);

    head = deleteByValue(head, 20);
    printf("After deleting value 20:\n");
    displayList(head);

    head = reverseList(head);
    printf("After reversing:\n");
    displayList(head);

    printf("Position of 10: %d\n", search(head, 10));

    printf("Cycle present? %s\n", detectCycle(head) ? "Yes" : "No");

    freeList(head);
    return 0;
}
