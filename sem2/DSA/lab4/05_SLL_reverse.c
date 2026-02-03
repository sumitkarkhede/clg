//5.Reverse a singly linked list in groups of size k.

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
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Reverse in groups of k
Node* reverseInGroups(Node* head, int k) {
    if (head == NULL) return NULL;

    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;

    // Check if at least k nodes exist
    Node* temp = head;
    for (int i = 0; i < k; i++) {
        if (temp == NULL)
            return head; // Less than k nodes, don't reverse
        temp = temp->next;
    }

    // Reverse first k nodes
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Recursively reverse remaining list
    if (next != NULL)
        head->next = reverseInGroups(next, k);

    return prev; // New head of this group
}

// Free memory
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
    int n, value, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    printf("Enter group size k: ");
    scanf("%d", &k);

    printf("\nOriginal List:\n");
    printList(head);

    head = reverseInGroups(head, k);

    printf("\nList After Reversing in Groups of %d:\n", k);
    printList(head);

    freeList(head);
    return 0;
}
