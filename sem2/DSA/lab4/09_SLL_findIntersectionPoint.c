// 9. Find the intersection point of two singly linked lists.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Get last node
Node* getTail(Node* head) {
    while (head && head->next)
        head = head->next;
    return head;
}

// Get length
int getLength(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection node
Node* getIntersection(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    Node *ptr1 = head1, *ptr2 = head2;

    if (len1 > len2)
        for (int i = 0; i < diff; i++) ptr1 = ptr1->next;
    else
        for (int i = 0; i < diff; i++) ptr2 = ptr2->next;

    while (ptr1 && ptr2) {
        if (ptr1 == ptr2)
            return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

// Print list
void printList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *common = NULL, *head1 = NULL, *head2 = NULL;
    int nCommon, n1, n2, value;

    printf("Enter number of nodes in COMMON list: ");
    scanf("%d", &nCommon);
    printf("Enter values for COMMON list:\n");
    for (int i = 0; i < nCommon; i++) {
        scanf("%d", &value);
        common = insertAtEnd(common, value);
    }

    printf("Enter number of unique nodes in List 1: ");
    scanf("%d", &n1);
    printf("Enter values for List 1 unique part:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        head1 = insertAtEnd(head1, value);
    }

    printf("Enter number of unique nodes in List 2: ");
    scanf("%d", &n2);
    printf("Enter values for List 2 unique part:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        head2 = insertAtEnd(head2, value);
    }

    // Attach common list to both
    if (head1 == NULL)
        head1 = common;
    else
        getTail(head1)->next = common;

    if (head2 == NULL)
        head2 = common;
    else
        getTail(head2)->next = common;

    printf("\nList 1:\n");
    printList(head1);

    printf("List 2:\n");
    printList(head2);

    Node* intersection = getIntersection(head1, head2);

    if (intersection)
        printf("\nIntersection found at node with value: %d\n", intersection->data);
    else
        printf("\nNo intersection found.\n");

    return 0;
}

