#ifndef NODE_CPP
#define NODE_CPP
#include <iostream>
class Node{
    public:
    int data;
    Node *next;

    Node(){
        data = 0;
        next = NULL;
    }
    Node(int d){
        data = d;
        next = NULL;
    }
};
#endif