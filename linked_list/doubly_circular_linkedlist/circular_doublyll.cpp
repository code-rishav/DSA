#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

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