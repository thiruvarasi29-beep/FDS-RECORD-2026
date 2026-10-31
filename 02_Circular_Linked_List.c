#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

struct node *createNode(int data) {
    struct node *newnode = malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void append(int data) {
    struct node *newnode = createNode(data);
    if (newnode == NULL) return;

    if (head == NULL)
        head = tail = newnode;
    else {
        tail->next = newnode;
        tail = newnode;
    }
    tail->next = head;
    printf("data appended :%d\n", data);
}

void prepend(int data) {
    struct node *newnode = createNode(data);
    if (newnode == NULL) return;

    if (head == NULL)
        head = tail = newnode;
    else {
        newnode->next = head;
        head = newnode;
    }
    tail->next = head;
    printf("data prepended :%d\n", data);
}

void insertAfter(int key, int data) {
    if (head == NULL) {
        printf("key element not found\n");
        return;
    }

    struct node *temp = head;
    do {
        if (temp->data == key) break;
        temp = temp->next;
    } while (temp != head);

    if (temp->data != key) {
        printf("key element not found\n");
        return;
    }

    struct node *newnode = createNode(data);
    if (newnode == NULL) return;

    newnode->next = temp->next;
    temp->next = newnode;
    if (temp == tail) tail = newnode;
    printf("inserted :%d after :%d\n", data, key);
}

void display(void) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

void deleteNode(int data) {
    if (head == NULL) {
        printf("key element not found\n");
        return;
    }

    struct node *temp = head, *prev = tail;
    do {
        if (temp->data == data) break;
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    if (temp->data != data) {
        printf("key element not found\n");
        return;
    }

    if (temp == head && temp == tail) {
        head = tail = NULL;
    } else {
        prev->next = temp->next;
        if (temp == head) head = temp->next;
        if (temp == tail) tail = prev;
        tail->next = head;
    }
    printf("data deleted :%d\n", data);
    free(temp);
}

int main(void) {
    append(10);
    append(20);
    append(30);
    prepend(40);
    display();

    printf("--\n");
    insertAfter(20, 25);
    display();

    printf("--\n");
    deleteNode(10);
    display();
    printf("--\n");
    display();

    return 0;
}
