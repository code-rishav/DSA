#ifndef linked_list_functions_h
#define linked_list_functions_h
#include "NODE.cpp"
#include <iostream>
using namespace std;
Node* sortedinsert(Node* head,int x){
    Node* temp = new Node(x);
    if(head==NULL){
        temp->next = NULL;
        return temp;
    }
    if(x<head->data){
        temp->next = head;
        return temp;
    }
    
    Node* curr = head;
    while(curr->next!=NULL && curr->next->data<x){
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

void printmiddle(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    cout<<slow->data<<endl;
}

void nposition1(Node* head,int pos){
    Node* curr = head;
    int len;
    while(curr->next!=NULL){
        len++;
        curr = curr->next;
    }

    for(int i=1;i<len-pos+1;i++)
        curr=curr->next;
    
    cout<<curr->data<<endl;
}

void nposition2(Node* head,int pos){
    if(head==NULL)
    return ;

    Node* first = head;
    for(int i=0;i<pos;i++){
        if(first==NULL) 
        return;
        first = first->next;
    }
    Node* second = head;
    while(first!=NULL){
        second = second->next;
        first = first->next;
    }
    cout<<second->data<<endl;

}
int main(){
    Node* head = new Node(1);
    Node* l1 = new Node(2);
    head->next = l1;
    Node* l2 = new Node(4);
    l1->next = l2;
    Node* l3 = new Node(5);
    l2->next = l3;
    printmiddle(head);

}

Node* merge(Node* h1,Node* h2){
    Node *head=NULL,*tail=NULL;
    Node* a = h1,*b= h2;
    if(a==NULL) return b;
    if(b==NULL) return a;
    if(a->data<b->data){
        head = tail = a;
        a = a->next;
    }
    else{
        head = tail = b;
        b = b->next;
    }
    while(a!=NULL && b!=NULL){
        if(a->data<b->data){
            tail->next = a;
            tail = a;
            a = a->next;
        }
        else{
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }
    if(a==NULL) tail->next = b;
    if(b==NULL) tail->next =a ;
    return head;

}


#endif