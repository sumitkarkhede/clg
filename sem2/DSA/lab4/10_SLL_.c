// 10. Flatten a linked list having next and bottom pointers into a single sorted list.

#include <stdio.h>
#include <stdlib.h> 

// Definition for a Node.
struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;
};  
// Function to merge two sorted linked lists
struct Node* merge(struct Node* a, struct Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    struct Node* result;

    if (a->data < b->data) {
        result = a;
        result->bottom = merge(a->bottom, b);
    } else {
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    result->next = NULL; // Ensure next pointer is NULL in merged list
    return result;
}

// Function to flatten the linked list
struct Node* flatten(struct Node* root) {
    if (root == NULL || root->next == NULL)
        return root;

    // Recursively flatten the next list
    root->next = flatten(root->next);

    // Merge this list with the next flattened list
    root = merge(root, root->next);

    return root;
}


//print the flattened linked list
void printFlattenedList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->bottom;
    }
    printf("NULL\n");
}
// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->bottom = NULL;
    return newNode;
}

int main() {
    // Creating a sample linked list with next and bottom pointers
    struct Node* head = createNode(5);
    head->bottom = createNode(7);
    head->bottom->bottom = createNode(8);
    head->bottom->bottom->bottom = createNode(30);

    head->next = createNode(10);
    head->next->bottom = createNode(20);

    head->next->next = createNode(19);
    head->next->next->bottom = createNode(22);
    head->next->next->bottom->bottom = createNode(50);

    head->next->next->next = createNode(28);
    head->next->next->next->bottom = createNode(35);
    head->next->next->next->bottom->bottom = createNode(40);
    head->next->next->next->bottom->bottom->bottom = createNode(45);

    // Flattening the linked list
    struct Node* flattenedList = flatten(head);

    // Printing the flattened list
    printFlattenedList(flattenedList);

    return 0;
}
