#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define MEMORY  1;
#define SUCCESS  0;
#define NOT_FOUND  2;
#define ELE_NULL  3;

int find(int x){
    return MEMORY;
}

void errors(int x){
    cout<<"Error";
}

int main(){
    errors(find(3));
}