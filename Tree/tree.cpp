#include <iostream>
#include <queue>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(){
        data = NULL;
        left = NULL;
        right = NULL;
    }
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
void inorder(Node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(Node* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    } 
}

int height(Node* root){
    if(root==NULL)
    return 0;
    else
    return max(height(root->left),height(root->right))+1;
}

void print(Node* root,int k){
    if(root==NULL) return;
    if(k==0)
    cout<<root->data<<" ";
    else{
        print(root->left,k-1);
        print(root->right,k-1); 
    }
}

void printlevelorder(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(q.empty()==false){
        Node *curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left!=NULL)
        q.push(curr->left);
        if(curr->right!=NULL)
        q.push(curr->right);
    }
}

void printlevelorderline(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        Node* curr = q.front();
        q.pop();
        if(curr==NULL){
            cout<<"\n";
            q.push(NULL);
            continue;
        }
        cout<<curr->data;
        if(curr->left!=NULL)
        q.push(curr->left);
        if(curr->right!=NULL)
        q.push(curr->right);
    }
}

void printlevelline2(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(q.empty()==false){
        int count = q.size();
        for(int i=0;i<count;i++){
            Node* curr = q.front();
            q.pop();
            cout<<curr->data<<" ";
            if(curr->left!=NULL)
            q.push(curr->left);
            if(curr->right!=NULL)
            q.push(curr->right);
        }
        cout<<"\n";
    }
}