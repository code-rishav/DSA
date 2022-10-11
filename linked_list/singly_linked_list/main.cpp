#include "LINKEDLIST_main.cpp"
Node* modify(Node* head){
    Node* curr = head;
    Node* temp = head->next;
    if(head==NULL)
    return NULL;
    if(curr->next==NULL)
    return head;

    while(curr->next!=NULL){
        if(temp->next==NULL)
        break;
     
        if(curr->data==temp->data){
            Node* t = temp;
            temp = temp->next;
            free(t);
        }
        else{
            curr->next = temp;
            curr = temp;
            temp = temp->next;
           
        }
       
    }
    if(curr->data==curr->next->data){
        delete curr->next;
        curr->next = NULL;
    }
    print(head);
    cout<<endl;
    return head;
}

int main(){
    Node *head = new Node(1);
    Node *l2 = new Node(2);
    head->next = l2;
    head = insertatBegin(head,1);
    head = insertatEnd(head,3);
    head = insertatEnd(head,5);
    
    //head->next->next = insertatEnd(l2->next->next,4);
    print(head);
    cout<<"\n";
    head = modify(head);
    print(head);

}
