#include<stdio.h>
#include<stdlib.h>
#include<queue>
struct bstNode {
    int data;
    struct bstNode* left;
    struct bstNode* right;
};      
struct bstNode* creaNode(int num) { // Funzione per creare un nodo (pulita)
    struct bstNode* newNode = (struct bstNode*)malloc(sizeof(struct bstNode));
    newNode->data = num;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct bstNode* insert(struct bstNode* root, int num) {// Funzione INSERT (necessaria per non sovrascrivere i dati!)
    if (root == NULL) return creaNode(num);
    if (num <= root->data) root->left = insert(root->left, num);
    else root->right = insert(root->right, num);
    return root;
}
void levelOrder(struct bstNode* root) {// Funzione per l'ordine di livello
    if (root == NULL) return;
    std::queue<struct bstNode*> q;
    q.push(root);
    while (!q.empty()) {
        struct bstNode* current = q.front();
        q.pop();
        printf("%d ", current->data);
        if (current->left != NULL) q.push(current->left);
        if (current->right != NULL) q.push(current->right);
    }
}
int main() {
    struct bstNode* root = NULL;
    int n, valore;          
    printf("Quanti nodi vuoi inserire? ");
    scanf("%d", &n);    
    for (int i = 0; i < n; i++) {// Inserimento dei nodi
        printf("Inserisci valore %d: ", i + 1);
        scanf("%d", &valore);
        root = insert(root, valore); // Costruisce l'albero correttamente
    }
    printf("L'ordine di livello dell'albero e': ");// Stampa l'ordine di livello
    levelOrder(root);// Chiamata alla funzione per stampare l'ordine di livello
    printf("\n");
    return 0;
}