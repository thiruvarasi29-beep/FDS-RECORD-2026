#include <stdio.h>
#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

int isFull(void) {
    return (rear + 1) % SIZE == front;
}

int isEmpty(void) {
    return front == -1;
}

void enQueue(int element) {
    if (isFull()) {
        printf("\nQueue is full!!\n");
        return;
    }

    if (isEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;

    items[rear] = element;
    printf("\nInserted -> %d\n", element);
}

int deQueue(void) {
    if (isEmpty()) {
        printf("\nQueue is empty!!\n");
        return -1;
    }

    int element = items[front];

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;

    printf("\nDeleted element -> %d\n", element);
    return element;
}

void display(void) {
    if (isEmpty()) {
        printf("\nEmpty Queue\n");
        return;
    }

    printf("\nFront -> %d\n", front);
    printf("Items -> ");
    int i = front;
    while (1) {
        printf("%d ", items[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\nRear -> %d\n", rear);
}

int main(void) {
    deQueue();

    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);
    enQueue(6);

    display();

    deQueue();
    display();

    enQueue(7);
    display();

    enQueue(8);

    return 0;
}
