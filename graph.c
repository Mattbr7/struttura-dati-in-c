#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *a[8];//array che contiene i puntatori alla testa delle liste di adiacenza
void create(int i)//funzione che crea la lista di adiacenza per il nodo i
{
    struct node *temp,*newnode;
    int j,n;
    printf("inserisci il numero di nodi adiacenti al nodo %d: ",i);//chiedo all'utente quanti nodi adiacenti ha il nodo i
    scanf("%d",&n);
    temp=a[i];//temp è un puntatore che mi serve per scorrere la lista di adiacenza del nodo i
    for(j=0;j<n;j++)//ciclo che mi permette di inserire i nodi adiacenti al nodo i
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("inserisci il nodo adiacente al nodo %d: ",i);//chiedo all'utente di inserire il nodo adiacente al nodo i
        scanf("%d",&newnode->data);//inserisco il nodo adiacente al nodo i
        newnode->next=NULL;
        if(temp==NULL)        {
            a[i]=newnode;//se la lista di adiacenza del nodo i è vuota, il nuovo nodo diventa la testa della lista
            temp=a[i];//temp punta alla testa della lista di adiacenza del nodo i
        }
        else        {
            temp->next=newnode;//se la lista di adiacenza del nodo i non è vuota, il nuovo nodo viene inserito alla fine della lista
            temp=temp->next;//temp punta al nuovo nodo inserito alla fine della lista di adiacenza del nodo i
        }
    }
}
void display(int i)//funzione che visualizza i nodi adiacenti al nodo i
{
    struct node *temp;//temp è un puntatore che mi serve per scorrere la lista di adiacenza del nodo i
    temp=a[i];
    printf("nodi adiacenti al nodo %d: ",i);//stampo i nodi adiacenti al nodo i
    while(temp!=NULL)    {
        printf("%d ",temp->data);
        temp=temp->next;//temp punta al nodo successivo della lista di adiacenza del nodo i
    }
    printf("\n");
}
void pulisci()//funzione che libera la memoria allocata per le liste di adiacenza
{
    struct node *temp,*temp1;
    int i;
    for(i=0;i<8;i++)    {
        temp=a[i];
        while(temp!=NULL)        {
            temp1=temp;
            temp=temp->next;//temp punta al nodo successivo della lista di adiacenza del nodo i
            free(temp1);//libero la memoria allocata per il nodo temp1
        }
    }
}

int main()
{
    int i;
    for(i=0;i<8;i++)    //inizializzo l'array a con NULL, in modo che le liste di adiacenza siano vuote all'inizio
    {
        a[i]=NULL;
    }
    for(i=0;i<8;i++)    //ciclo che mi permette di creare le liste di adiacenza per i nodi da 0 a 7
    {
        create(i);
    }
    for(i=0;i<8;i++)    //ciclo che mi permette di visualizzare i nodi adiacenti per i nodi da 0 a 7
    {
        display(i);
    }
    return 0;
}