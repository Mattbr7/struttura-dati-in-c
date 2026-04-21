#include<stdio.h>
#include<stdlib.h>
struct bstNode {
    int data;
    struct bstNode* left;
    struct bstNode* right;
};

struct bstNode* creaNode(int num) {
    struct bstNode* newNode = (struct bstNode*)malloc(sizeof(struct bstNode));
    newNode->data = num;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct bstNode* insert(struct bstNode* root, int num) {
    if (root == NULL) return creaNode(num);
    if (num <= root->data) root->left = insert(root->left, num);
    else root->right = insert(root->right, num);
    return root;
}
struct bstNode* TrovaAltezza(struct bstNode* root) {
    if (root == NULL) {
        return -1; // Altezza di un albero vuoto è -1
    }
    int leftHeight = TrovaAltezza(root->left);
    int rightHeight = TrovaAltezza(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

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

    if (root != NULL) {
        printf("L'altezza dell'albero e': %d\n", TrovaAltezza(root));
    } else {
        printf("Albero vuoto!\n");
    }

    return 0;
}