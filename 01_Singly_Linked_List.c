#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void append(int data) {
    struct node *newnode = malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    printf("data appended:%d\n", data);
}

void prepend(int data) {
    struct node *newnode = malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = data;
    newnode->next = head;
    head = newnode;
    printf("data prepended:%d\n", data);
}

void display(void) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insert(int data, int pos) {
    if (pos < 0) {
        printf("Invalid position\n");
        return;
    }

    struct node *newnode = malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = data;
    newnode->next = NULL;

    if (pos == 0) {
        newnode->next = head;
        head = newnode;
    } else {
        struct node *curr = head, *prev = NULL;
        int i = 0;
        while (curr != NULL && i < pos) {
            prev = curr;
            curr = curr->next;
            i++;
        }
        if (i != pos) {
            printf("Invalid position\n");
            free(newnode);
            return;
        }
        newnode->next = curr;
        prev->next = newnode;
    }
    printf("data inserted:%d at position:%d\n", data, pos);
}

void search(int data) {
    struct node *temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("data found @:%d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("data not found\n");
}

void deleteNode(int data) {
    struct node *temp = head, *prev = NULL;
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nelement not found\n");
        return;
    }
    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    printf("\nelement deleted:%d\n", temp->data);
    free(temp);
}

int main(void) {
    append(10);
    append(20);
    append(30);
    display();

    prepend(40);
    display();

    deleteNode(20);
    display();

    insert(50, 0);
    display();

    printf("\nsearch element: 40\n");
    search(40);
    printf("list data\n");
    display();

    return 0;
}
