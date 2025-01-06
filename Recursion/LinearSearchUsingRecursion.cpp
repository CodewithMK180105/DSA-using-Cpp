// Perform the linear Search using Recursion.

#include<iostream>
using namespace std;
int LinearSearch(int arr[], int n, int idx,int target){
    if(idx==n) return -1;
    if(target==arr[idx]) return idx;
    return LinearSearch(arr,n,idx+1,target); 
}
int main(){
    int arr[]={5,4,7,1,3,6,9,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<LinearSearch(arr,n,0,88);
    return 0;
}