#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;     
};
struct Node* creaNode(int numero){
    struct Node* newNode =new Node;
    newNode->data= numero;
    newNode->left= NULL;
    newNode->right=NULL;    
    return newNode;
}
struct Node* insert(struct Node* root , int numero)
{        if(root==NULL){
            return creaNode(numero);
        }
        else if(numero<=root->data)
        {            root->left=insert(root->left, numero);
        }
        else if(numero>=root->data){
            root->right=insert(root->right, numero);
        }
        return root;
};
struct Node* cercavalore(struct Node* root, int numero){
    //non trovato,quindi albero vuoto
    if(root==NULL){
        return NULL;
    }
         if(numero==root->data){
            return root;
         }
         else if(numero<root->data){
            return cercavalore(root->left,numero);
         }
         else{           
            return cercavalore(root->right,numero);
         }
}
int main(){
    struct Node*root=NULL;
    root=insert(root, 10);
    insert(root,4);
    insert(root,12);
    insert(root,18);
    insert(root,7);
    insert(root,16);
    insert(root,3);
int numero;
    cout<<"dimmi un numero"<<endl;
    cin>>numero;
    struct Node* valore_trovato= cercavalore(root,numero);
    if(valore_trovato!=NULL){//trova il valore;
        cout<<"il valore trovato è, "<<valore_trovato->data;
    }
    return 0;
}