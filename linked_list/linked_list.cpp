#include <iostream>
using namespace std;
class Node{
    public:
    Node* next;
    int val;
    Node(){
        next = NULL;
    }
    Node(int val){
        this->val = val;
        next = NULL;
    }
};
Node* createLinkedList(int ar[],int len){
    Node* head = new Node(ar[0]);
    Node* curr = head;
    int i=1;
    while(i!=len){
        Node* temp = new Node(ar[i]);
        curr->next = temp;
        curr = curr->next;
        i++;
    }
    return head;
}
void sortedinsert(Node* head,Node* node){
    while(head->next!=NULL && head->next->val<node->val){
           head = head->next;
       } 
       node->next = head->next;
       head->next = node;
}
Node* sort(Node* head){
    if(head->next==NULL || head->next->next==NULL)
    return head;
    Node* first;
    Node* last;
    Node* curr;
    Node* next;
    first = head; 
    last = head->next;
    curr = last->next;
    last->next = NULL;
    while(next!=NULL){
        next = curr->next;
        sortedinsert(head,curr);
        curr = next;
    }
    curr->next = last;
    return head;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<"\n";
}
int main(){
    int ar[] = {1,9,2,8,3,7};
    Node* head = createLinkedList(ar,6);
    print(head);
    head = sort(head);
    print(head);

}