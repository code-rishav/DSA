#include <iostream>
#include "S.cpp"

using namespace std;

int main(){
    int *arr;
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;
    arr=new int[size];
    cout << "Enter the elements of the array : ";
    for (int i=0; i<size; i++)
    {cin >> arr[i];}
    cout << "Your array : ";
    for (int i=0; i<size; i++)
    {cout << arr[i] << " ";}
    cout << endl;
    
    int option;
    cout << "Enter 1 to sort the array using bubble sort." << endl;
    cout << "Enter 2 to sort the array using insertion sort." << endl;
    cout << "Enter 3 to sort the array using selection sort." << endl;
    cout << "Enter 4 to exit the program.\n" << endl;
    cout << "Your option : ";
    cin >> option;
    Sort<int> sort;
    switch (option)
    {
        case 1:
                sort.bubbleSort(arr, size);
                cout << "Array after bubble sort : ";
                break;
        case 2: 
                //sort.insertionSort(arr, size);
                cout << "Array after insertion sort : ";
                break;
        case 3: 
                //sort.selectionSort(arr, size);
                cout << "Array after selection sort : ";
                break;
        case 4:
                cout << "Program Terminated." << endl;
                delete [] arr;
                return 0;
    }
    for (int i=0; i<size; i++)
    {cout << arr[i] << " ";}
    cout << endl;
    
    
    
    
    
    
    delete [] arr;
    return 0;
}