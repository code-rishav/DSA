#include<iostream>
using namespace std;

void rev(int arr[],int low,int high){
    while(low<high){
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
}
int rotateD(int arr[],int d,int n){
    rev(arr,0,d-1);
    rev(arr,d,n-1);
    rev(arr,0,n-1);
}


void leaders(int arr[],int n){
    int lead = arr[n-1];
    cout<<lead<<endl;
    for(int i=n-2;i>=0;i--){
        if(lead<arr[i]){
            lead = arr[i];
            cout<<lead<<endl;
        }
    }
}

int maxDiff(int ar[],int n){
    int minval = ar[0];
    int res = ar[1]-ar[0];
    for(int j=1;j<n;j++){
        res = max(res,ar[j]-minval);
        minval = min(minval,ar[j]);
    }
    return res;
}