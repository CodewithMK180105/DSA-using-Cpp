// Print the array elements in the reverse order.

#include<iostream>
using namespace std;
void printReverse(int arr[], int idx, int n){
    if(idx==n) return;
    printReverse(arr,idx+1,n);
    cout<<arr[idx]<<" ";
}
int main(){
    int arr[]={5,4,7,1,3,6,9,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    printReverse(arr,0,n);
    return 0;
}