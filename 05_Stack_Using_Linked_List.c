#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int data) {
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("element pushed:%d\n", data);
}

int pop(void) {
    if (top == NULL) {
        printf("\nEMPTY STACK\n");
        return -1;
    }

    struct node *temp = top;
    int temp_data = top->data;
    top = top->next;
    free(temp);
    return temp_data;
}

void display(void) {
    if (top == NULL) {
        printf("\nStack Underflow\n");
        return;
    }

    printf("\nThe stack is:\n");
    struct node *temp = top;
    while (temp != NULL) {
        printf("%d--->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n\n");
}

int main(void) {
    push(10);
    push(20);
    push(30);

    display();

    printf("\nelement popped %d\n", pop());
    printf("element popped %d\n", pop());
    display();

    return 0;
}
