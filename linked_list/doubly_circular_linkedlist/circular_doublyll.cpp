#include "NODE2.cpp"
using namespace std;

Node* insertatHead(Node* head,int x){
    Node* temp = new Node(x);
    if(head==NULL){
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }
    temp->next = head;
    temp->prev = head->prev;
    head->prev->next = temp;
    head->prev = temp;
    return temp;

}