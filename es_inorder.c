#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};  
void inorder(struct node *root)//funzione per eseguire la visita in ordine dell'albero
{
    if(root==NULL)
    {
        return; //se il nodo è NULL, ritorna senza fare nulla
    }
    inorder(root->left); //visita il sottoalbero sinistro
    printf("%d ",root->data);//stampa il valore del nodo corrente
    inorder(root->right);//visita il sottoalbero destro
}
struct node* createNode(int data)//funzione per creare un nuovo nodo
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;//assegna il valore al campo data del nuovo nodo
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct node* trovaminimo(struct node*root)
{
    if(root==NULL)
    {
        return NULL;
    }
    while(root->left!=NULL)//continua a spostarsi verso sinistra finché non raggiungi il nodo più a sinistra, che è il nodo con il valore minimo
    {
        root=root->left;
    }
    return root;
}
struct node* getsuccessor(struct node* root, int data)//funzione per trovare il successore di un nodo con un dato specifico
{
    struct node* current = root;//trova il nodo con il dato specificato
    while(current!=NULL && current->data!=data)
    {
        if(data<current->data)//se il dato è minore del valore del nodo corrente, continua a cercare nel sottoalbero sinistro
        {
            current=current->left;
        }
        else
        {
            current=current->right;
        }
    }
    if(current==NULL)
    {
        return NULL;//se il nodo non viene trovato, ritorna NULL    
}
    if(current->right!=NULL)
    {
        return trovaminimo(current->right);//se il nodo ha un sottoalbero destro, il successore è il nodo con il valore minimo in quel sottoalbero
    }
    else
    {
        struct node* successor = NULL;//se il nodo non ha un sottoalbero destro, il successore è uno degli antenati
        struct node* ancestor = root;//inizia a cercare dagli antenati partendo dalla radice
        while(ancestor!=current)//continua a cercare finché non raggiungi il nodo corrente
        {
            if(current->data<ancestor->data)
            {
                successor=ancestor;//se il nodo corrente è un discendente sinistro, l'antenato è un potenziale successore
                ancestor=ancestor->left;//continua a cercare nell'albero verso il nodo corrente
            }
            else
            {
                ancestor=ancestor->right;//se il nodo corrente è un discendente destro, continua a cercare nell'albero verso il nodo corrente senza aggiornare il successore
            }
        }
        return successor;//ritorna il successore trovato
    }
}
int main()
{
         /*20
        10      30
    2         25  35
      15     11      40
    
*/




    struct node* root = createNode(20);//crea la radice dell'albero con il valore 20
    root->left = createNode(10);//crea il nodo sinistro della radice con il valore 10
    root->left->left = createNode(2);//crea il nodo sinistro del nodo 10 con il valore 2
    root->left->right = createNode(15);//crea il nodo destro del nodo 10 con il valore 15
    root->right = createNode(30);//crea il nodo destro della radice con il valore 30
    root->right->left = createNode(25);//crea il nodo sinistro del nodo 30 con il valore 25
    root->right->right = createNode(35);//crea il nodo destro del nodo 30 con il valore 35
    root->right->right->right = createNode(40);//crea il nodo destro del nodo 35 con il valore 40
    root->right->left->left = createNode(11);//crea il nodo sinistro del nodo 25 con il valore 11
    printf("Inorder traversal: ");      
    inorder(root);
    printf("\n");
    int data = 30;//dato per cui vogliamo trovare il successore
    struct node* successor = getsuccessor(root, data);//trova il successore del nodo con il valore specificato
    if (successor != NULL) {
        printf("Successor of %d is %d\n", data, successor->data);
    } else {
        printf("No successor found for %d\n", data);
    }
    return 0;
}   