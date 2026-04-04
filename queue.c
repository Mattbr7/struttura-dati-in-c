#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* createNode(int numero)
{
    //crea un nuovo nodo con il numero dato e restituisce un puntatore a esso
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data= numero;
    newNode->next= NULL;

    return newNode;
}
struct node* enqueue(struct node* rear, int numero)
{
    //aggiunge un nuovo nodo con il numero dato alla fine della coda e restituisce il nuovo rear
    struct node* newNode = createNode(numero);
    if(rear==NULL)    {
        rear = newNode;
    }
    else{
        //se la coda non è vuota, collega il nuovo nodo al nodo attualmente in coda e aggiorna il rear per puntare al nuovo nodo
        rear->next = newNode;
        rear = newNode;
    }
    return rear;
}
struct node* dequeue(struct node** front)
{  
    //rimuove il nodo in testa alla coda e restituisce un puntatore a esso. Se la coda è vuota, restituisce NULL
     if(*front==NULL){
        printf("la coda è vuota\n");
        return NULL;
    }
    struct node* temp = *front;
    *front = (*front)->next;//aggiorna il puntatore front per puntare al nodo successivo nella coda
    return temp;
}
int main(){
    struct node* front = NULL;
    struct node* rear = NULL;
    rear = enqueue(rear, 10);
    if(front==NULL){//se la coda è vuota, il front deve puntare al primo nodo aggiunto
        front = rear;
    }
    rear = enqueue(rear, 20);//aggiunge un nuovo nodo con il numero dato alla fine della coda e restituisce il nuovo rear
    rear = enqueue(rear, 30);
    struct node* temp = dequeue(&front);//rimuove il nodo in testa alla coda e restituisce un puntatore a esso. Se la coda è vuota, restituisce NULL
    if(temp!=NULL){//se la coda non è vuota, stampa il numero estratto e libera la memoria del nodo rimosso
        printf("il numero estratto è %d\n", temp->data);
        free(temp);//libera la memoria del nodo rimosso
    }
    return 0;
}   