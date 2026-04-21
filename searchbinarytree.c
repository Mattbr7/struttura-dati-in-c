#include<stdio.h>
#include<stdlib.h>
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
int search(struct bstNode* root, int num) { // Funzione di ricerca
    if (root == NULL) return 0; // Non trovato
    if (root->data == num) return 1; // Trovato!
    if (num < root->data) return search(root->left, num); // Cerca a sinistra
    else return search(root->right, num); // Cerca a destra
}
int main() {
    struct bstNode* root = NULL;
    int n, valore;
    printf("Quanti nodi vuoi inserire? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Inserisci valore %d: ", i + 1);
        scanf("%d", &valore);
        root = insert(root, valore); // Costruisce l'albero correttamente
    }
    int numToSearch;
    printf("Inserisci il numero da cercare: ");
    scanf("%d", &numToSearch);
    if (search(root, numToSearch)) {
        printf("Il numero %d e' presente nell'albero.\n", numToSearch);
    } else {
        printf("Il numero %d non e' presente nell'albero.\n", numToSearch);
    }
    return 0;
}