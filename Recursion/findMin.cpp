// Find minimum element in an array using recursion.

#include<iostream>
using namespace std;
int findMin(int arr[], int idx, int n){
    if(idx==n-1) return arr[idx];
    return min(arr[idx],findMin(arr,idx+1,n));
}
int main(){
    int arr[]={4,2,9,-7,1,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<findMin(arr,0,n);
    return 0;
}