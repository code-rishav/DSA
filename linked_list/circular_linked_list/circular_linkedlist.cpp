#include "NODE.cpp"
using namespace std;


    Node* insertatHead(Node* head,int x){
        Node* temp = new Node(x);
        if(head==NULL){
            temp->next = temp;
            return temp;
        }
        else{
            temp->next = head->next;
            head->next = temp;
           int t = head->data;
            head->data = temp->data;
            temp->data = t;
            return head;
        }
    }

     Node* insertatEnd(Node* head,int x){
        Node* temp = new Node(x);
        if(head==NULL){
            temp->next = temp;
            return temp;
        }
        else{
            temp->next = head->next;
            head->next = temp;
           int t = head->data;
            head->data = temp->data;
            temp->data = t;
            return temp;
        }
    }

    Node* delhead(Node* head){
        if(head==NULL)
        return NULL;
        if(head->next==NULL){
            delete head;
            return NULL;
        }
        Node* temp = head->next;
        int t = head->data;
        head->data = temp->data;
        temp->data = t;
        head->next = temp->next;
        delete temp;
        return head;
    }

    void print(Node* head){
        if(head==NULL)
        return;
        Node *temp = head;
        do{
            cout<<temp->data<<"->";
            temp = temp->next;
    
        }while(temp!=head);
        cout<<endl;
    }

    Node* delpos(Node* head,int k){
        if(k==1){
            return delhead(head);
        }
        int pos = 0;
        Node* temp = head;
        while(temp!=NULL && pos<k-2){
            temp = temp->next;
            pos++;
        }
        Node* t = temp->next;
        temp->next = temp->next->next;
        delete t;
        return head;
    }