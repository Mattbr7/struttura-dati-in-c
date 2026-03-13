#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
int a[MAX_SIZE];
int top = -1;
void push(int x) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    a[++top] = x;
}
void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return;
    }
    top--;
}
int peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1; // Return a sentinel value to indicate stack is empty
    }
    return a[top];
}
int main() {
    push(2);
    push(6);
    push(7);
    push(8);
    pop();
    printf("%d\n", peek());
    pop();
    printf("%d\n", peek());
    pop();
    printf("%d\n", peek());
    pop();
    printf("%d\n", peek());
    return 0;
}
