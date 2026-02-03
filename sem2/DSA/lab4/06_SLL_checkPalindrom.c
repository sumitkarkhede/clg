// 6. Check whether a singly linked list is a palindrome.
// Example: 9 → 8 → 8 → 9 → NULL → Palindrome

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Reverse linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* next = NULL;

    while (head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

// Check palindrome
bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL)
        return true;

    Node *slow = head, *fast = head;

    // Find middle
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    Node* secondHalf = reverseList(slow->next);

    Node* firstHalf = head;
    Node* tempSecond = secondHalf;
    bool result = true;

    // Compare halves
    while (tempSecond != NULL) {
        if (firstHalf->data != tempSecond->data) {
            result = false;
            break;
        }
        firstHalf = firstHalf->next;
        tempSecond = tempSecond->next;
    }

    // Restore list (optional but good practice)
    slow->next = reverseList(secondHalf);

    return result;
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

    printf("\nLinked List:\n");
    printList(head);

    if (isPalindrome(head))
        printf("\nResult: The linked list is a Palindrome \n");
    else
        printf("\nResult: The linked list is NOT a Palindrome \n");

    freeList(head);
    return 0;
}
