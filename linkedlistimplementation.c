#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* top = NULL;
void push(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}
void pop(){
    if(top == NULL){
        printf("Stack underflow\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    free(temp);
}
void display(){
    struct Node* temp = top;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }    printf("\n");
}
int main(){
    push(10);
    push(20);
    push(30);
    printf("Stack elements: ");
    display();
    pop();
    printf("Stack elements after pop: ");
    display();
    return 0;
}