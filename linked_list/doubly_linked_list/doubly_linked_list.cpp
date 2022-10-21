#ifndef DOUBLY_LINKEDLIST_CPP
#define DOUBLY_LINKEDLIST_CPP
#include "NODE2.cpp"
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int x){
        data=x;
        next = NULL;
        prev = NULL;
    }
};
Node* insertatBegin(Node* head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    if(head==NULL){
        temp->prev = head;
    }
    return temp;

}
Node* insertatEnd(Node* head,int data){
    Node* temp = new Node(data);
    if(head==NULL) return temp;
    Node* curr = head;
    while(curr->next!=NULL)
    curr = curr->next;
    curr->next = temp;
    temp->prev = curr;
    return head;
}

Node* reverse(Node* head){
    if(head==NULL||head->next==NULL) return NULL;
    Node* curr = head;
    Node* temp=NULL;
    while(curr!=NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    return temp->prev;
}
Node* delhead(Node* head){
    if(head==NULL) return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    else{

        Node* temp = head;
        delete head;
        temp = temp->next;
        temp->prev = NULL;
        return temp;
    }
}

Node* deltail(Node* head){
    if(head==NULL) return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    Node* curr = head;
    while(curr->next->next!=NULL){
        curr = curr->next;
    }
    Node* temp = curr;
    curr->next = NULL;
    delete temp;
    return head;
}
void print(Node *head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"\n";
}

#endif