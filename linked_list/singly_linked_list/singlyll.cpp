#ifndef SINGLYLINKEDLIST_CPP
#define SINGLYLINKEDLIST_CPP
#include "NODE.cpp"
using namespace std;
class singlyll{

    Node *head;
    Node *tail;
    public:
    singlyll(){
        head = NULL;
        tail = NULL;
    }
    int insertatBegin(int x){
        Node* temp = new Node(x);
        if(temp==NULL)
        return -1;
        if(head==NULL){
            head = temp;
            tail=temp;
        }
        else{
            temp->next = head;
            head = temp;
        }
        return 0;
    }

    int insertatEnd(int x){
        Node *temp = new Node(x);
        if(temp==NULL)
        return -1;
        if(tail==NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        return 0;
    }
    
    int insertatPos(int pos,int x){
        Node* temp = new Node(x);
        if(pos==1){
        temp->next = head;
        head = temp;
        return 0;
        }
        Node* curr = head;
        for(int i=1;i<pos-2&& curr!=NULL;i++)
         curr = curr->next;
        if(curr==NULL)
         return -1;
        temp->next = curr->next;
        curr->next = temp;
        return 0;
    }
    int delhead(){
        if(head==NULL)
        return -1;
        else if(tail==head){
            delete head;
            head = NULL;
            tail = NULL;
            return 0;
        }
        else{
            Node *temp = head;
            delete head;
            head = temp->next;
            return 0;
        }
    }


    int deltail(){
        if(tail==NULL)
        return -1;
        else if(tail==head){
            delete head;
            head = NULL;
            tail = NULL;
            return 0;
        }
        else{
            Node* temp = head;
            while(temp->next->next!=NULL)
            temp = temp->next;

            delete temp->next;
            temp->next = NULL;
            tail = temp;
            return 0;
        }
    }
    void display(){
        Node *p = head;
        while(p!=NULL){
            cout<<p->data<<"->";
            p = p->next;
        }
        cout<<endl;
    }
};
#endif