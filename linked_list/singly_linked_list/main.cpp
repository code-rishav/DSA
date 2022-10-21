#include "LINKEDLIST_main.cpp"
int main(){
    Node *head = new Node(1);
    Node *l2 = new Node(2);
    head->next = l2;
    head = insertatBegin(head,1);
    head = insertatEnd(head,3);
    head = insertatEnd(head,5);
     print(head);
     cout<<"\n";
    //head->next->next = insertatEnd(l2->next->next,4);
    print(head);
    cout<<"\n";
    head = swapkthnode(head,5,2);
    print(head);
    cout<<endl;

}
