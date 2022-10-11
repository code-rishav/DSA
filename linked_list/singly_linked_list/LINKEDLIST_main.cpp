#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP
#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

Node* insertatBegin(Node* head,int x){
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}
Node* insertatEnd(Node *head,int x){
    Node *temp = new Node(x);
    if(head==NULL)
    return temp;
    Node *curr = head;
    while(curr->next!=NULL){
        curr = curr->next;
    }
    curr->next = temp;
    return head; 
}

Node* insertPos(Node* head,int pos,int x){
    Node* temp = new Node(x);
    if(pos==1){
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    for(int i=1;i<pos-2&& curr!=NULL;i++)
    curr = curr->next;
    if(curr==NULL)
    return NULL;
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

Node* delhead(Node* head){
    if(head==NULL)
    return NULL;
    else{
        Node* temp = head;
        delete head;
        return temp;
    }
}

Node* deltail(Node* head){
    if(head==NULL)
    return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }

    Node* curr = head;
    while(curr->next->next!=NULL)
    curr = curr->next;
    delete curr->next;
    curr->next = NULL;
    return head;
}

int search_r(Node* head,int x){
    if(head==NULL)
    return -1;
    if(head->data==x)
    return 1;
    else{
        int res = search_r(head->next,x);
        if(res==-1)
        return -1;
        else
        return res+1;
    }
}
int search_l(Node* head,int x){
    int pos = 1;
    Node* curr = head;
    while(curr!=NULL){
        if(curr->data==x)
        return pos;
        else{
            pos++;
            curr = curr->next;
        }
    }
    return -1;
}

void print(Node *head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
}



#endif
