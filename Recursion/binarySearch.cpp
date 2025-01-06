// Perform the binary Search using Recursion.

#include<iostream>
using namespace std;
int binarySearch(int arr[], int low, int high,int target){
    if(low>high) return -1;
    int mid=low+(high-low)/2;
    if(target==arr[mid]) return mid;
    if(target<arr[mid]) return binarySearch(arr,low,mid-1,target);
    else return binarySearch(arr,mid+1,high,target);
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int low=0;
    int high=n-1;
    cout<<binarySearch(arr,low,high,0);
    return 0;
}