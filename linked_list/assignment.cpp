#include "NODE.cpp"
#include <iostream>
using namespace std;
class linkedlist{
    Node* head;
    Node* tail;
    public:

    linkedlist(){
        head = NULL;
        tail = NULL;
    }

    linkedlist(int x){
        head = NULL;
        tail = NULL;
    }
    int addatHead(int x){
        Node* temp = new Node(x);
        if(head==NULL){
            head = tail = temp;
            return 0;
        }
        else{
            temp->next = head;
            head = temp;
            return 0;
        }
    }

    void odd(){
        cout<<"Odd elements in the list are: ";
        Node* curr = head;
        while(curr!=NULL){
            if(curr->data%2!=0)
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
        return;
    }

    void largest(){
        Node* curr = head;
        int max = head->data;
        while(curr!=NULL){
            if(max<curr->data)
            max = curr->data;
            curr = curr->next;
        }
        cout<<"Largest element in the list is: "<<max<<endl;
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

int main(){
    linkedlist l1;
    l1.addatHead(2);
    l1.addatHead(3);
    l1.addatHead(7);
    l1.addatHead(5);
    l1.addatHead(4);

    int op;
    
while(true){
    cout<<"1.to add at head\n2.to display odd nodes\n3.to find the largest element\n4.to display list\n";
    cin>>op;
    switch(op){
        case 1:
        int ele;
        cout<<"Enter the element to be added at head: ";
        cin>>ele;
        l1.addatHead(ele);
        break;
        
        case 2:
        l1.odd();
        break;

        case 3:
        l1.largest();
        break;

        case 4:
        l1.display();
        break;

        default:
        cout<<"Enter valid choice"<<endl;
        break;
    }
}

}