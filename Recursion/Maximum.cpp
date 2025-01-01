#include<iostream>
using namespace std;
int maximum(int *arr,int idx,int n){
    if(idx==n-1) return arr[idx];
    return max(arr[idx],maximum(arr,idx+1,n));
}
void maximumEle(int *arr, int idx, int n, int maxVal){
    if(idx==n){
        cout<<maxVal;
        return;
    }
    if(arr[idx]>maxVal) maxVal=arr[idx];
    maximumEle(arr,idx,n,maxVal);
}
int main(){
    int arr[]={3,100,31,3,2,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<maximum(arr,0,n);
    return 0;
}