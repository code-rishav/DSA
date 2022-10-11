#ifndef S_CPP
#define S_CPP
#include "st.h"
#include <utility>
template <typename T>
void Sort<T>::bubbleSort(T *arr, int size){
    int totalComparisons=0;
    int swaps=0;
    for (int i=0; i<size-1; i++)
    {
        swaps=0;
        for (int j=0; j<size-1-i; j++, totalComparisons++)
        {
            if (arr[j]>arr[j+1])
            {
                std::swap(arr[j], arr[j+1]);
                swaps++;
            }
        }
        if (swaps==0)
        {break;}
    }
}
#endif
