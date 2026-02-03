//1. Find the middle element of a singly linked list.
//Example: 11 → 22 → 33 → 44 → 55 → NULL → Middle = 33

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;

} Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;    
}
Node* findMiddle(Node* head){
    Node *slow = head;
    Node *fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void displayList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(){
    Node* head = createNode(11);
    head->next = createNode(22);
    head->next->next = createNode(33);
    head->next->next->next = createNode(44);
    head->next->next->next->next = createNode(55);

    printf("Linked List: ");
    displayList(head);

    Node* middle = findMiddle(head);
    if(middle != NULL){
        printf("Middle Element: %d\n", middle->data);
    } else {
        printf("The list is empty.\n");
    }

    return 0;
}
