#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;
    Node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};
Node* insert(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;
}
Node* findmin(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
Node* deletenode(Node* root,int val){
    if(root==NULL){
        return root;
    }
    if(val<root->data){
        root->left=deletenode(root->left,val);
    }
    else if(val>root->data){
        root->right=deletenode(root->right,val);
    }
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        Node* temp=findmin(root->right);
        root->data=temp->data;
        root->right=deletenode(root->right,temp->data);
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Node* root=NULL;
    root=insert(root,5);
    insert(root,3);
    insert(root,7);
    insert(root,2);
    insert(root,4);
    insert(root,6);
    insert(root,8);
    cout<<"Inorder traversal before deletion: ";
    inorder(root);
    cout<<endl;
    root=deletenode(root,3);
    root=deletenode(root,7);
    cout<<"Inorder traversal after deletion: ";
    inorder(root);
    cout<<endl;
    return 0;
}