// Write a program to find the kth smallest element in an array using quick sort

#include<iostream>
using namespace std;
int partition(int arr[],int left,int right){
    int pivot=arr[right];
    int i=left-1;
    for(int j=left;j<right;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[right]);
    return i+1;
}
int kthElement(int arr[],int left,int right,int k){
    int pos=partition(arr,left,right);
    if(pos==k-1) return arr[pos];
    else if(pos-left>k-1) return kthElement(arr,left,pos-1,k);
    else return kthElement(arr,pos+1,right,k);
}
int main(){
    int arr[]={3,5,2,1,4,7,8,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k; cin>>k;
    cout<<kthElement(arr,0,n-1,k);
    return 0;
}