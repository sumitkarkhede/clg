// 8. Merge two sorted singly linked lists into one sorted list.
// Example: 1→4→8 and 2→3→9 → 1→2→3→4→8→9

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

// Split list into two halves used in merge sort
void splitList(Node* source, Node** front, Node** back) {
    Node* slow = source;
    Node* fast = source->next;
    // Move fast two nodes and slow one node to find the middle
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

// Merge two sorted lists
Node* sortedMerge(Node* a, Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    Node* result = NULL;

    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

// Merge Sort for linked list
Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node *a, *b;
    splitList(head, &a, &b);

    a = mergeSort(a);
    b = mergeSort(b);

    return sortedMerge(a, b);
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
    Node* list1 = NULL;
    Node* list2 = NULL;
    Node* merged = NULL;
    int n1, n2, value;

    printf("Enter number of nodes in List 1: ");
    scanf("%d", &n1);
    printf("Enter values for List 1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        list1 = insertAtEnd(list1, value);
    }

    printf("Enter number of nodes in List 2: ");
    scanf("%d", &n2);
    printf("Enter values for List 2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        list2 = insertAtEnd(list2, value);
    }

    printf("\nOriginal List 1:\n");
    printList(list1);
    printf("Original List 2:\n");
    printList(list2);

    // Sort both lists
    list1 = mergeSort(list1);
    list2 = mergeSort(list2);

    printf("\nSorted List 1:\n");
    printList(list1);
    printf("Sorted List 2:\n");
    printList(list2);

    // Merge sorted lists
    merged = sortedMerge(list1, list2);

    printf("\nFinal Merged & Sorted List:\n");
    printList(merged);

    freeList(merged);
    return 0;
}

