//Delete the Nth node from the end of the list in one traversal.

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Insert at tail (helper for building list)
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

// Delete Nth node from end (one pass)
Node* deleteNthFromEnd(Node* head, int N) {
    if (head == NULL || N <= 0) return head;

    Node *fast = head, *slow = head;

    // Move fast N steps ahead
    for (int i = 0; i < N; i++) {
        if (fast == NULL)
            return head;  // N greater than length
        fast = fast->next;
    }

    // If fast is NULL, delete head
    //to delete first node or N is equal to length of linked list
    if (fast == NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // Move both pointers
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }//slow is now at (length-N)th node from start and fast is at last node

    // Delete slow->next
    //slow is pointing to (length-N)th node
    Node* nodeToDelete = slow->next;//nth node from end
    slow->next = nodeToDelete->next;//bypass the nth node from end
    free(nodeToDelete);

    return head;
}

// Display list
void displayList(Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
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

    // Creating list: 1 -> 2 -> 3 -> 4 -> 5
    for (int i = 1; i <= 5; i++)
        head = insertAtEnd(head, i);


    printf("Original List:\n");
    displayList(head);

    int N = 2;
    head = deleteNthFromEnd(head, N);

    printf("After deleting %dth node from end:\n", N);
    displayList(head);

    freeList(head);
    return 0;
}
