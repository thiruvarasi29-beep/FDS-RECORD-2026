#include <stdio.h>

int stack[100], n, top, i;

void push(int x) {
    if (top >= n - 1) {
        printf("\nSTACK is overflow\n");
    } else {
        top++;
        stack[top] = x;
        printf("\nelement pushed into stack:%d\n", x);
    }
}

void pop(void) {
    if (top <= -1) {
        printf("\nStack is underflow\n");
    } else {
        printf("\nThe popped element is %d\n", stack[top]);
        stack[top] = 0;
        top--;
    }
}

void display(void) {
    if (top >= 0) {
        printf("\nThe elements in STACK:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    } else {
        printf("\nThe STACK is empty\n");
    }
}

int main(void) {
    top = -1;
    n = 5;

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);

    display();

    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();

    return 0;
}
