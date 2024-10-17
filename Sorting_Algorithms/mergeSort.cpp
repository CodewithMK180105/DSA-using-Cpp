#include<iostream>
using namespace std;
void merge(int *arr,int left,int mid,int right){
    int l=mid-left+1;
    int r=right-mid;

    int a[l],b[r];

    for(int i=0;i<l;i++) a[i]=arr[left+i];
    for(int i=0;i<r;i++) b[i]=arr[mid+1+i];

    int i=0,j=0,k=left;

    while(i<l && j<r){
        if(a[i]<b[j]) arr[k++]=a[i++];
        else arr[k++]=b[j++];
    }

    while(i<l){
        arr[k++]=a[i++];
    }
    
    while(j<r){
        arr[k++]=b[j++];
    }
}
void mergeSort(int *arr,int left,int right){
    if(left>=right) return;
    int mid=(left+right)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}
int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    mergeSort(arr,0,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}