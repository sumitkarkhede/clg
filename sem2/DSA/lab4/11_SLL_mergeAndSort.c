// 11. Merge K sorted linked lists into one sorted linked list.
// Example: L1=1→5, L2=2→6, L3=3→4 → 1→2→3→4→5→6

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

Node* insertAtEnd(Node* head, int value) {
    Node* newNode = createNode(value);
    if (!head) return newNode;

    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

void printList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Split list into two halves
void splitList(Node* source, Node** front, Node** back) {
    Node* slow = source;
    Node* fast = source->next;

    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

// Merge two sorted lists
Node* mergeSorted(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result = NULL;

    if (a->data <= b->data) {
        result = a;
        result->next = mergeSorted(a->next, b);
    } else {
        result = b;
        result->next = mergeSorted(a, b->next);
    }
    return result;
}

// Merge Sort for linked list
Node* mergeSort(Node* head) {
    if (!head || !head->next)
        return head;

    Node *a, *b;
    splitList(head, &a, &b);

    a = mergeSort(a);
    b = mergeSort(b);

    return mergeSorted(a, b);
}

int main() {
    int k;

    printf("Enter number of linked lists (K): ");
    scanf("%d", &k);

    Node* lists[k];

    for (int i = 0; i < k; i++) {
        lists[i] = NULL;
        int n, value;

        printf("\nEnter number of nodes in List %d: ", i + 1);
        scanf("%d", &n);

        printf("Enter values for List %d (unsorted allowed):\n", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &value);
            lists[i] = insertAtEnd(lists[i], value);
        }

        // Sort this list
        lists[i] = mergeSort(lists[i]);

        printf("Sorted List %d:\n", i + 1);
        printList(lists[i]);
    }

    // Merge all sorted lists
    Node* result = lists[0];
    for (int i = 1; i < k; i++) {
        result = mergeSorted(result, lists[i]);
    }

    printf("\nFinal Merged Sorted List:\n");
    printList(result);

    return 0;
}

