#include<stdio.h>
#include<stdlib.h>
struct node
{
    //creo la struttura del nodo per la pila
    int data;
    struct node* next;
   
}Node;
struct node* head=NULL;//faccio puntare la testa a NULL
void push(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=head;
    head=newnode;
    //funzione per inserire un elemento nella pila
}
char pop(){
    if(head==NULL){
        return '\0';
    }
    struct node* temp=head;
    char data=temp->data;
    head=head->next;
    free(temp);
    return data;
    //funzione per rimuovere un elemento dalla pila
}   
int isEmpty() {
    return head == NULL;
    // per verificare se la pila è vuota o meno
}
int isbalanced(char* exp){ //funzione per verificare se l'espressione è bilanciata o meno
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
                if(isEmpty()){
                return 0;
            }
            char top=pop();
            if((exp[i]==')' && top=='(') || (exp[i]=='}' && top=='{') || (exp[i]==']' && top=='[')){
                continue;
            }
            else{
                return 0;
            }
            
        }
        //funzione per verificare se l'espressione è bilanciata o meno
    }
    return isEmpty(); //alla fine verifico se la pila è vuota o meno, se è vuota allora l'espressione è bilanciata altrimenti no
}
void freeStack(){
    while(!isEmpty()){
        pop();
    }
    //funzione per liberare la memoria allocata per la pila
}
int main(){
    char exp[100];
    printf("Enter the expression: ");
    scanf("%s",exp);
    //chiedo all'utente di inserire l'espressione da verificare
    if(isbalanced(exp)){
        printf("The expression is balanced.\n");
    }
    else{
        printf("The expression is not balanced.\n");
    }
    freeStack();
    return 0;
}