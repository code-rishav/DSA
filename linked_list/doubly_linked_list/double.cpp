#include "doubly_linked_list.cpp"
int main(){
    Node* l = new Node(5);
    l =insertatBegin(l,6);
    l = insertatBegin(l,8);
    
    //print(l);
   // l = reverse(l);
    l = deltail(l);
   // l = insertatEnd(l,100);
    l = insertatEnd(l,44);
    print(l);

}

