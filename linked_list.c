/*
 Program Name : Singly Linked List
 Operations   : Insertion, Deletion, Traversal
 Language     : C
 Platform     : macOS
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Insert at beginning
void insertBegin(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Delete a node
void deleteNode(struct Node** head, int key) {
    struct Node *temp = *head, *prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Display list
void traverse(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertBegin(&head, 10);
    insertBegin(&head, 20);
    insertBegin(&head, 30);

    printf("Linked List:\n");
    traverse(head);

    deleteNode(&head, 20);
    printf("After Deletion:\n");
    traverse(head);

    return 0;
}
