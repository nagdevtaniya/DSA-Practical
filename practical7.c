#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode; // Point to itself
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode; // Point to itself
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to delete a node
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return;

    struct Node *curr = *head, *prev = NULL;
    do {
        if (curr->data == key) {
            if (prev) {
                prev->next = curr->next;
            } else { // Deleting head
                if (curr->next == *head) { // Only one node
                    free(curr);
                    *head = NULL;
                    return;
                } else {
                    struct Node* last = *head;
                    while (last->next != *head) {
                        last = last->next;
                    }
                    last->next = curr->next;
                    *head = curr->next;
                }
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != *head);
}

// Function to traverse the list
void traverse(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main function to demonstrate the circular linked list
int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);

    printf("List after insertions: ");
    traverse(head); // Output: 5 -> 10 -> 20 -> (head)

    deleteNode(&head, 10);
    printf("List after deletion of 10: ");
    traverse(head); // Output: 5 -> 20 -> (head)

    return 0;
}
