// Find the sum of all the element in an array using recursion.

#include<iostream>
using namespace std;
int Sum(int arr[], int idx, int n){
    if(idx==n-1) return arr[idx];
    return arr[idx]+Sum(arr,idx+1,n);
}
int main(){
    int arr[]={4,2,9,-7,1,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<Sum(arr,0,n);
    return 0;
}