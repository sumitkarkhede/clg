// 7. Move the last node of a linked list to the front.
// Example: 10 → 20 → 30 → 40 → NULL → 40 → 10 → 20 → 30 → NULL

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

// Move last node to front
Node* moveLastToFront(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* secondLast = NULL;
    Node* last = head;

    while (last->next != NULL) {//traverse to the last node
        secondLast = last;
        last = last->next;
    }

    secondLast->next = NULL; // Remove last node
    last->next = head;       // Link last node to front
    head = last;             // Update head

    return head;
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
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    printf("\nOriginal List:\n");
    printList(head);

    head = moveLastToFront(head);

    printf("\nList After Moving Last Node to Front:\n");
    printList(head);

    freeList(head);
    return 0;
}
