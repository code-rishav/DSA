#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP
#include "NODE.cpp"
using namespace std;

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

Node* reverse_i(Node* head){

    if(head==NULL)
    return NULL;
    
    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
    
}

Node* reverse_r1(Node* head){
    if(head==NULL || head->next==NULL)
    return head;
    Node* rest_head = reverse_r1(head->next);
    Node* rest_tail = head->next;
    rest_tail = head;
    head->next = NULL;
    return rest_head;
}

Node* reverse_r2(Node* curr,Node* prev){
    if(curr==NULL)
    return prev;
    Node* next = curr->next;
    curr->next = prev;
    return reverse_r2(next,curr);
    
}

Node* reverse_k(Node* head,int k){
        Node* curr = head, *next = NULL,*prev = NULL;
        int count = 0;
        while(curr!=NULL && count<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(next!=NULL){
            Node* rest_head = reverse_k(next,k);
            head->next = rest_head;
        }
        return prev;

}

Node *reverseK(Node *head,int k){
    Node *curr=head,*prevFirst=NULL;
    bool isFirstPass=true;
    while(curr!=NULL){
        Node *first=curr,*prev=NULL;
        int count=0;
        while(curr!=NULL&&count<k){
        Node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
        }
        if(isFirstPass){head=prev;isFirstPass=false;}
        else{prevFirst->next=prev;}
        prevFirst=first;
    }
    return head;
}

Node* segregate(Node* head){
    Node *es=NULL,*ee=NULL,*os=NULL,*oe=NULL;
    for(Node *curr=head;curr!=NULL;curr=curr->next){
       int x = curr->data;
        if(x%2==0){
            if(es==NULL)
            es = ee = curr;
            else{
                ee->next = curr;
                ee = ee->next;
            }
        }
        else{
            if(os==NULL)
            os = oe = curr;
            else{
                oe->next = curr;
                oe = oe->next;
            }
        }
        if(os==NULL || es==NULL)
        return head;
        ee->next = os;
        oe->next = NULL;
    }
    return es;
}

void print(Node *head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
}

Node* swapkthnode(Node* head, int num, int K)
    {
        Node *first = head,*second = head,*prev1=NULL,*prev2=NULL;
        for(int i=0;i<K;i++){
            if(first==NULL)
            return head;
            prev1 = first;
            first = first->next;
        }
        while(first!=NULL){
            prev2 = second;
            second = second->next;
            first = first->next;
        }
        Node* temp = second;
        second->next = prev1->next->next;
        prev1->next =second;
        temp->next = prev2->next->next;
        prev2->next = temp;
        return head;
        
}

#endif
