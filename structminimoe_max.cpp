#include<iostream>
using namespace std;

struct bstNode {
    int data;
    bstNode* left;
    bstNode* right;
};

// Funzione per creare un nodo (pulita)
bstNode* creaNode(int num) {
    bstNode* newNode = new bstNode();
    newNode->data = num;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Funzione INSERT (necessaria per non sovrascrivere i dati!)
bstNode* insert(bstNode* root, int num) {
    if (root == NULL) return creaNode(num);
    if (num <= root->data) root->left = insert(root->left, num);
    else root->right = insert(root->right, num);
    return root;
}

// TROVA MINIMO: vai a sinistra finché puoi
int TrovaMinimo(bstNode* root) {
    if (root == NULL) return -1;
    if (root->left == NULL) return root->data; // Trovato!
    return TrovaMinimo(root->left); // Continua a scendere
}

// TROVA MASSIMO: vai a destra finché puoi
int TrovaMassimo(bstNode* root) {
    if (root == NULL) return -1;
    if (root->right == NULL) return root->data; // Trovato!
    return TrovaMassimo(root->right); // Continua a scendere
}

int main() {
    bstNode* root = NULL;
    int n, valore;

    cout << "Quanti nodi vuoi inserire? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Inserisci valore " << i + 1 << ": ";
        cin >> valore;
        root = insert(root, valore); // Costruisce l'albero correttamente
    }

    if (root != NULL) {
        cout << "Il minimo e': " << TrovaMinimo(root) << endl;
        cout << "Il massimo e': " << TrovaMassimo(root) << endl;
    } else {
        cout << "Albero vuoto!" << endl;
    }

    return 0;
}