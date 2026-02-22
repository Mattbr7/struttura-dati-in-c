#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int dato;
    struct nodo *next;
};
struct nodo* inverti_lista(struct nodo *head){
    struct nodo *prev = NULL, *curr = head, *next;

    while(curr != NULL){
        next = curr->next;   
        curr->next = prev;  
        prev = curr;         
        curr = next;    
    }     
    return prev; 
}
struct nodo* stampalista(struct nodo *head){
    struct nodo *temp = head;
    while(temp != NULL){
        printf("%d ", temp->dato);
        temp = temp->next;
    }
    printf("\n");
    return head;
}


int main(void) {
    struct nodo *n1, *n2, *n3, *n4, *head, *temp;

    n1 = malloc(sizeof(struct nodo));
    n2 = malloc(sizeof(struct nodo));
    n3 = malloc(sizeof(struct nodo));
    n4 = malloc(sizeof(struct nodo));

    head = n1;
    n1->dato = 1;
    n2->dato = 3;
    n3->dato = 2;
    n4->dato = 4;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->dato);
        temp = temp->next;
    }
    printf("\n");

    head = inverti_lista(head);
    stampalista(head);

    free(n1);
    free(n2);
    free(n3);
    free(n4);

    return 0;
}
