#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H
#include <iostream>
using namespace std;
template <typename T>
class Lsearch{

    int size;
    T *arr;
    public:
    Lsearch();
    int search(T ele);
};
template <typename T>
    Lsearch<T>::Lsearch(){
        cout<<"Enter the size";
        cin>>size;
        arr = new T[size];
        cout<<"Enter the elements: "<<endl;
        for(int i=0;i<size;i++)
        cin>>arr[i];
    }
template <typename T>
int Lsearch<T>::search(T ele){
    for(int i=0;i<size;i++){
        if(ele==arr[i])
        return i;
    }
    return -1;
} 
#endif