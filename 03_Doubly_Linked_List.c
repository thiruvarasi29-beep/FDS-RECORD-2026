#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL, *tail = NULL;
int total_elements = 0;

void append(int data) {
    struct node *newnode = malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = data;
    newnode->prev = tail;
    newnode->next = NULL;

    if (head == NULL)
        head = tail = newnode;
    else {
        tail->next = newnode;
        tail = newnode;
    }
    total_elements++;
    printf("the element appended: %d\n", data);
}

void prepend(int data) {
    struct node *newnode = malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = head;

    if (head == NULL)
        head = tail = newnode;
    else {
        head->prev = newnode;
        head = newnode;
    }
    total_elements++;
    printf("the element prepended: %d\n", data);
}

void deleteNode(int data) {
    struct node *curr = head;
    while (curr != NULL && curr->data != data)
        curr = curr->next;

    if (curr == NULL) {
        printf("\nelement not found\n");
        return;
    }

    if (curr->prev != NULL)
        curr->prev->next = curr->next;
    else
        head = curr->next;

    if (curr->next != NULL)
        curr->next->prev = curr->prev;
    else
        tail = curr->prev;

    free(curr);
    total_elements--;
    printf("the element deleted: %d\n", data);
}

void display(void) {
    struct node *temp = head;
    printf("\nNULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverse(void) {
    struct node *temp = tail;
    printf("\nNULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main(void) {
    append(10);
    append(20);
    append(30);
    display();

    prepend(40);
    display();
    printf("\ntotal elements:%d\n", total_elements);

    printf("----\n");
    deleteNode(30);
    display();
    printf("\ntotal elements:%d\n", total_elements);
    reverse();

    return 0;
}
