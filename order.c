#include<stdio.h>
#include<stdlib.h>
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};
struct Node* creaNode(char lettera) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = lettera;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, char lettera) {
    if (root == NULL) return creaNode(lettera);
    if (lettera <= root->data) root->left = insert(root->left, lettera);
    else root->right = insert(root->right, lettera);
    return root;
}
void preOrder(struct Node* root) {
    if (root == NULL) return;
    printf("%c ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}
int main() {
    struct Node* root = NULL;
    int n;
    char lettera;
    printf("Quanti nodi vuoi inserire? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Inserisci lettera %d: ", i + 1);
        scanf(" %c", &lettera);
        root = insert(root, lettera);
    }
    printf("L'ordine pre-order dell'albero e': ");
    preOrder(root);
    printf("\nL'ordine in-order dell'albero e': ");
    inorder(root);
    printf("\n");
    return 0;
}