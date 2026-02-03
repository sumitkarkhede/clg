//3. Remove duplicates from a sorted singly linked list.

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

// Remove duplicates from UNSORTED list
Node* removeDuplicates(Node* head) {
    Node* current = head;

    while (current != NULL) {
        Node* prev = current;
        Node* temp = current->next;

        while (temp != NULL) {//traverse the rest of the list to find duplicates
            if (temp->data == current->data) {//duplicate found 
                prev->next = temp->next;//bypass the duplicate node
                free(temp);
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
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

    head = removeDuplicates(head);

    printf("\nList After Removing Duplicates:\n");
    printList(head);

    freeList(head);
    return 0;
}


