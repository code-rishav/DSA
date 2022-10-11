#include <iostream>
#include "binary_search.h"
using namespace std;
int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int* ar = new int[size];
    for(int i=0;i<size;i++)
    cin>>ar[i];
    int ele;
    cout<<"Enter the element to be searched: ";
    cin>>ele;
    binary<int>b;
    cout<<"Element found at: "<<b.search(0,size-1,ar,((size-1)/2),ele);
}