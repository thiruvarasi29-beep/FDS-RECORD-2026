#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value) {
    struct node *ptr = malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    ptr->data = value;
    ptr->next = NULL;

    if (front == NULL && rear == NULL)
        front = rear = ptr;
    else {
        rear->next = ptr;
        rear = ptr;
    }
    printf("Node is Inserted:%d\n\n", value);
}

int dequeue(void) {
    if (front == NULL) {
        printf("\nUnderflow\n");
        return -1;
    }

    struct node *temp = front;
    int temp_data = front->data;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    return temp_data;
}

void display(void) {
    if (front == NULL && rear == NULL) {
        printf("\nQueue is Empty\n");
        return;
    }

    printf("The queue is\n");
    struct node *temp = front;
    while (temp != NULL) {
        printf("%d--->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n\n");
}

int main(void) {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("Deleted element: %d\n", dequeue());
    display();

    return 0;
}
