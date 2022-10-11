#ifndef BINARY_H
#define BINARY_H

template <typename T>
class binary{
    public:
    int search(int l,int r,T arr[],int size,int ele);
};

template <typename T>
int binary<T>::search(int l,int r,T arr[],int mid,int ele){
        
        if(l>=r)
        return -1;
        if(arr[mid] == ele)
        return mid;
        if(arr[mid]>ele){
            r = mid-1;
            mid = (r+l)/2;
             return search(l,r,arr,mid,ele);
        }
        else{
            l = mid+1;
            mid = (r+l)/2;
            return search(l,r,arr,mid,ele);
        }
}
#endif
