#include<iostream>
using namespace std;
int Summision(int *arr,int idx,int n){
    if(idx==n-1) return arr[idx];
    return arr[idx]+Summision(arr,idx+1,n);
}
int main(){
    int arr[]={3,10,3,2,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<Summision(arr,0,n);
    return 0;
}