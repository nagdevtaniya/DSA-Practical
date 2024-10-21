#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    char data;
    struct Node* next;
};
void push(struct Node** top, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}
char pop(struct Node** top) {
    if (*top == NULL) {
        return '\0';
    }
    struct Node* temp = *top;
    char popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}
char peek(struct Node* top) {
    return (top != NULL) ? top->data : '\0';
}
int isEmpty(struct Node* top) {
    return top == NULL;
}
void READ(struct Node* Undo) {
    struct Node* temp = Undo;
    while (temp != NULL) {
        printf("%c", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void QUERY(char Q[][10], int N) {
    struct Node* Undo = NULL;
    struct Node* Redo = NULL;
    for (int i = 0; i < N; i++) {
        if (strcmp(Q[i], "UNDO") == 0) {
            char X = pop(&Undo);
            if (X != '\0') {
                push(&Redo, X);
            }
        } else if (strcmp(Q[i], "REDO") == 0) {
            char X = pop(&Redo); 
            if (X != '\0') {
                push(&Undo, X);
            }
        } else if (strcmp(Q[i], "READ") == 0) {
            READ(Undo); 
        } else {
            char character = Q[i][6]; 
            push(&Undo, character);
        }
    }
}
int main() {
    char Q[][10] = { "WRITE A", "WRITE B", "WRITE C","WRITE A","WRITE C", "UNDO", "READ", "REDO", "READ" };
    int N = sizeof(Q) / sizeof(Q[0]);
    QUERY(Q, N);
    return 0;
}
