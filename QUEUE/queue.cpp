#include <iostream>
#include <stdio.h>
using namespace std;
class Queue{
    int *q;
    int front;
    int rear;
    

    public:
    int size;

    Queue(int s){
        size = s;
        q = new int[size];
        front = 0;
        rear = 0;
    }

    void enqueue(int x){
        if(rear>size || (front==rear && front!=0)){
        cout<<"Stack Overflow"<<endl;
        return;
        }
        if(front>0 && rear==size)
        rear = 0;
        q[rear++] = x;
    }

    int dequeue(){
        if(front==-1){
        cout<<"Stack Underflow"<<endl;
        return -1000;
        }
        if(front == size)
        front = 0;
        return q[front++];
    }

    bool empty(){
        if(front!=rear && rear <size-1)
        return true;
        else
        return false;
    }

    void print(){
        int i;
        for(i=front;i<size;i++)
        cout<<q[i]<<' ';
        cout<<endl;
    }

};

int main(){
  Queue q(5);
  
  q.enqueue(4);
  q.enqueue(1);
  q.enqueue(7);
  q.enqueue(6);
  q.enqueue(8);
  cout<<q.empty()<<endl;

  
  cout<<q.dequeue()<<endl;
  cout<<q.dequeue()<<endl;
  cout<<q.empty()<<endl;
  
  q.enqueue(4);
  q.enqueue(5);
  q.enqueue(99);
  cout<<q.empty()<<endl;
  
  cout<<q.dequeue()<<endl;
  
  q.enqueue(6);
  cout<<q.empty()<<endl;
  cout<<q.dequeue()<<endl;
  cout<<q.dequeue()<<endl;
  cout<<q.dequeue()<<endl;
  cout<<q.dequeue()<<endl;
  cout<<q.dequeue()<<endl;
  cout<<q.empty()<<endl;
  
  q.enqueue(7);
  
  
}