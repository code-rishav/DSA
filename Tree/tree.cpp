#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(){
        data = INT_MIN;
        left = NULL;
        right = NULL;
    }
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root,int x){
        Node* ele = new Node(x);
        if(root==NULL){
            root = ele;
            return root;
        }
        Node* curr = root;
        while(curr!=NULL){
            if(x<curr->data){
                if(curr->left==NULL){
                    curr->left = ele;
                    return root;
                }
                else
                curr = curr->left;
            }
            else if(x>curr->data){
                if(curr->right==NULL){
                    curr->right = ele;
                    return root;
                }
                else
                curr = curr->right;
            }
            else
            return root;
        }
        return root;
}

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

int count(Node* root){
    if(root==NULL)
    return 0;
    else{
        return 1+count(root->left)+count(root->right);
    }
}

int getmax(Node* root){
    if(root==NULL)
    return INT16_MIN;
    else
    return max(root->data,max(getmax(root->left),getmax(root->right)));
}

int maxlevel;
void leftview(Node* root,int level){
    if(root==NULL)
    return;
    if(maxlevel<level){
        cout<<root->data;
        maxlevel = level;
    } 
    leftview(root->left,level+1);
    leftview(root->right,level+1);
}

void leftview_loop(Node* root){
    if(root==NULL)
    return;
    queue<Node*>q;
    q.push(root);
    while(q.empty()==false){
        int count = q.size();
        for(int i=0;i<count;i++){
            Node* curr = q.front();
            q.pop();
            if(i==1)
            cout<<curr->data<<" ";
            if(curr->left!=NULL)
            q.push(curr->left);
            if(curr->right!=NULL)
            q.push(curr->right);
        }
    }
}

bool childsum(Node* root){
    if(root==NULL)
    return true;
    if(root->left==NULL && root->right==NULL)
    return true;
    int sum=0;
    if(root->left!=NULL)
    sum+=root->left->data;
    if(root->right!=NULL)
    sum+=root->right->data;
    return (root->data==sum && childsum(root->left) && childsum(root->right));
}

bool isbalanced1(Node* root){
    if(root==NULL) return true;
    int lh = height(root->left);
    int rh = height(root->right);
    return (abs(lh-rh)<=1 && isbalanced1(root->left) && isbalanced1(root->right));
}

int isbalanced2(Node* root){
    if(root==NULL) return 0;
    int lh = isbalanced2(root->left);
    if(lh==-1) return -1;
    int rh = isbalanced2(root->right);
    if(rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    else
    return max(lh,rh)+1;
}

int maxWidth(Node* root){
    if(root==NULL) return 0;
    int res = 0;
    queue<Node*>q;
    q.push(root);
    while(q.empty()==false){
        int count = q.size();
        res = max(res,count);
        for(int i=0;i<q.size();i++){
            Node* curr = q.front();
            q.pop();
            if(curr->left!=NULL)q.push(curr->left);
            if(curr->right!=NULL)q.push(curr->right);
        }
    }
    return res;
}

Node* BTtoDLL(Node* root){
    if(root==NULL) return root;
    static Node* prev = NULL;
    Node* head = BTtoDLL(root->left);
    if(prev==NULL)
    head = root;
    else{
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BTtoDLL(root->right);
    return head;
}

Node* construct(int in[],int pre[]){
    int pivot;
    Node* root = new Node(pre[0]);
    pivot = find_p(in,root->data);

}

int find_p(int ar[],int ele){
    int size = sizeof(ar)/sizeof(int);
    for(int i=0;i<size;i++){
        if(ar[i]==ele)
        return i;
    }
}

void printspiral(Node* root){
    if(root==NULL) return;
    queue<Node*> q;
    stack<int> s;
    bool reverse = false;
    q.push(root);
    while(q.empty()==false){
        int count = q.size();
        for(int i=0;i<count;i++){
            Node* curr = q.front();
            q.pop();
            if(reverse)
            s.push(curr->data);
            else
            cout<<curr->data<<" ";

            if(curr->left!=NULL)
            q.push(curr->left);
            if(curr->right!=NULL)
            q.push(curr->right);     
        }
        if(reverse){
            while(s.empty()==false){
                cout<<s.top()<<" ";
                s.pop();
            }
        }
        reverse = !reverse;
        cout<<endl;
    }

}

void printspiral2(Node* root){
    if(root==NULL) return;

    stack<Node*>s1;
    stack<Node*> s2;
    s1.push(root);
    while(s1.empty()==false || s2.empty()==false){
        while(s1.empty()==false){
            Node* temp = s1.top();
            s1.pop();
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
            s2.push(temp->left);
            if(temp->right!=NULL)
            s2.push(temp->right);
        }
        while(s2.empty()==false){
            Node* temp2 = s2.top();
            s2.pop();
            cout<<temp2->data<<" ";
            if(temp2->right!=NULL)
            s2.push(temp2->right);
            if(temp2->left!=NULL)
            s2.push(temp2->left);
        }
        cout<<endl;
    }

}

int res=0;
int diameter2(Node* root){
    if(root==NULL) return 0;
    int lh = diameter2(root->left);
    int rh = diameter2(root->right);
    res = max(res,1+lh+rh);
    return 1+max(lh,rh);
}

int diameter1(Node* root){
    if(root==NULL) return 0;
    int d1 = 1+height(root->left)+height(root->right);
    int d2 = diameter1(root->left);
    int d3 = diameter1(root->right);
    return max(d1,max(d2,d3));
}

bool path(Node* root,int n,vector<Node*> v){
    if(root==NULL) return false;
    if(root->data==n) return true;
    if(path(root->left,n,v)==false || path(root->right,n,v)==false) 
    return false;
    v.pop_back();
    return false;
}

Node* lca1(Node* root,int n1,int n2){
    vector<Node*> path1,path2;
    if(path(root,n1,path1)==false||path(root,n2,path2)==false) return NULL;
    for(int i=0;i<path1.size()-1;i++){
        if(path1[i+1]==path2[i+1])
        return path1[i];
    }
    return NULL;
}

Node* lca2(Node* root,int n1,int n2){
    if(root==NULL) return NULL;
    if(root->data==n1||root->data==n2) return root;

    Node* lca_1 = lca2(root->left,n1,n2);
    Node* lca_2 = lca2(root->right,n1,n2);

    if(lca_1!=NULL && lca_2!=NULL)
        return root;
    if(lca_1!=NULL)
        return lca_1;
    else
        return lca_2;
}

int countNodes(Node* root){
    if(root==NULL)
    return 0;
    int lh=0,rh=0;
    Node* curr = root;
    while(curr!=NULL){
        lh++;
        curr = curr->left;
    }
    curr = root;
    while(curr!=NULL){
        rh++;
        curr = curr->right;
    }
    if(lh==rh)
    return pow(2,lh)-1;
    else
    return 1+ countNodes(root->left)+countNodes(root->right);
}

void serialise(Node* root, vector<int>&arr){
    if(root==NULL){
        arr.push_back(-1);
        return;
    }
    arr.push_back(root->data);
    serialise(root->left,arr);
    serialise(root->right,arr);
    return;
}

//value of index is passed as 0 initially
Node* deserialise(vector<int> &arr,int index){
    if(index==arr.size())
    return NULL;

    int val = arr[index];
    index++;
    if(val==-1)
    return NULL;

    Node *root = new Node(val);
    root->left = deserialise(arr,index);
    root->right = deserialise(arr,index);
    return root;
}