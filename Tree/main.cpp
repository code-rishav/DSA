#include "tree.cpp"
int main(){
    Node* root= new Node(1);
    Node* l1 = new Node(2);
    root->left = l1;
    Node* l2 = new Node(3);
    l1->left = l2;
    Node* r1 = new Node(4);
    l1->right = r1;
    Node* r2 = new Node(5);
    root->right = r2;
    Node* r3 = new Node(6);
    root->right->right = r3;

    flat(root);
}