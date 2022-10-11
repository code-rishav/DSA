#include "circular_linkedlist.cpp"

int main(){
   Node* head = new Node(3);
   head->next = head;
   print(head);
   head =  insertatHead(head,4);
   print(head);
   head = insertatEnd(head,5);
   print(head);
   head = delpos(head,2);
   print(head);
}