#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", value);
}

void pop() {
    if (!top) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    printf("%d popped from stack\n", temp->data);
    free(temp);
}

void display() {
    if (!top) {
        printf("Stack is empty\n");
        return;
    }
    for (struct Node* temp = top; temp; temp = temp->next)
        printf("%d ", temp->data);
    printf("\n");
}

int main() {
    push(10); push(20); push(30);
    display();
    pop();
    display();
    return 0;
}

