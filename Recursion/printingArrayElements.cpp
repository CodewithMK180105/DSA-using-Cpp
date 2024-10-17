#include<iostream>
using namespace std;
void print(int *arr,int i,int n){
    if(i==n) return;
    cout<<arr[i]<<" ";
    print(arr,i+1,n);
}
int main(){
    int arr[]={6,1,9,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    print(arr,0,n);
    return 0;
}