#include<iostream>
#include<string>
using namespace std;
class Stack{
    private:
        struct Node{
            int  data;
            Node* next;
        };
        Node *head;
    public:
        Stack(){
            head = NULL;
        }
        void push(int data){
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = head;
            head = newNode;
        }
        void pop(){
            if(head == NULL){
                cout << "Stack underflow" << endl;
                return;
            }
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        void top(){
            if(head == NULL){
                cout << "Stack is empty" << endl;
                return;
            }
            cout << "Top element: " << head->data << endl;
        }
        void display(){
            Node* temp = head;
            while(temp != NULL){
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
};
int main(){
    Stack s;
    s.push(3);
    s.push(5);
    s.push(7);
    s.push(6);
    cout << "Stack contenuto:" << endl;
    s.display();
    s.pop();
    cout << "Stack contenuto dopo aver tolto 1 elemento:" << endl;
    s.display();
    s.top();
    s.pop();
    cout << "Stack contenuto dopo  aver tolto 2 elementi:" << endl;
    s.display();
    s.top();
    return 0;
}