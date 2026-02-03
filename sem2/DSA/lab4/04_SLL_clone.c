// 4. Clone a linked list with next and random pointers.

#include <stdio.h>
#include <stdlib.h>

// Definition for a Node.
struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};


struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    // 1. Create a copy of each node and insert it between the original node and its next node.
    struct Node* curr = head;
    while (curr != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = curr->val;
        newNode->next = curr->next;
        newNode->random = NULL; // Random pointer is set in the next step

        curr->next = newNode;
        curr = newNode->next;
    }

    // 2. Set the random pointers of the cloned nodes.
    curr = head;
    while (curr != NULL) {
        if (curr->random != NULL) {
            // The random pointer of the clone node (curr->next) points to the
            // clone of the original random target (curr->random->next).
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    // 3. Separate the original and cloned lists.
    struct Node* original = head;
    struct Node* cloneHead = head->next;
    struct Node* clone = cloneHead;

    while (original != NULL) {
        original->next = original->next->next;
        if (clone->next != NULL) {
            clone->next = clone->next->next;
        }

        original = original->next;
        clone = clone->next;
    }

    return cloneHead;
}

void printList(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("Node: %d, Next: %d, Random: %d\n", curr->val, 
               curr->next ? curr->next->val : -1, 
               curr->random ? curr->random->val : -1);
        curr = curr->next;
    }
}


int main() {
    // Create the original linked list (example structure from image might be complex to hardcode precisely)
    // A simpler example: 1 -> 2 -> 3
    // 1's random points to 3, 2's random points to 1, 3's random points to NULL
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->val = 1;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->val = 2;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->val = 3;
    head->next->next->next = NULL; 
    head->random = head->next->next; // 1's random is 3
    head->next->random = head;      // 2's random is 1
    head->next->next->random = NULL; // 3's random is NULL

    printf("Original list:\n");
    printList(head);

    struct Node* clonedList = copyRandomList(head);

    printf("\nCloned list:\n");
    printList(clonedList);

    return 0;
}
