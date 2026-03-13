#include <stdio.h>
#include <stdlib.h>

struct node {
    int numero;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void create(int n1, int n2, int n3, int n4) {
    struct node *nodo1, *nodo2, *nodo3, *nodo4;

    nodo1 = malloc(sizeof(struct node));
    nodo2 = malloc(sizeof(struct node));
    nodo3 = malloc(sizeof(struct node));
    nodo4 = malloc(sizeof(struct node));

    nodo1->numero = n1; 
    nodo1->prev = NULL;  
    nodo1->next = nodo2;
    nodo2->numero = n2; 
    nodo2->prev = nodo1; 
    nodo2->next = nodo3;
    nodo3->numero = n3; 
    nodo3->prev = nodo2; 
    nodo3->next = nodo4;
    nodo4->numero = n4; 
    nodo4->prev = nodo3; 
    nodo4->next = NULL;

    head = nodo1;
}


void stampa() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->numero);
        temp = temp->next;
    }
    printf("\n");
}

void reverse() {
    struct node *temp = NULL;
    struct node *current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }
}
void inserisciInCoda(int valore) {
    struct node *nuovo = malloc(sizeof(struct node));
    nuovo->numero = valore;
    nuovo->next = NULL;

    if (head == NULL) {
        nuovo->prev = NULL;
        head = nuovo;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = nuovo;
    nuovo->prev = temp;
}
int main() {
    int n1, n2, n3, n4;
    printf("Inserisci 4 numeri: ");
    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
    create(n1, n2, n3, n4);
    printf("Lista normale: ");
    stampa();
    printf("Lista invertita:\n");
    reverse();
    stampa();
    printf("double linked list: ");
    stampa();
    inserisciInCoda(4);

    return 0;
}
