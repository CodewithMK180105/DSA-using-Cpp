#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ansarr[n];
    int k; cin>>k;
    k%=n;

    int j=0;

    // Inserting first k elements
    for(int i=n-k;i<n;i++){
        ansarr[j++]=arr[i];
    }
    // Inserting next n-k elements
    for(int i=0;i<=k;i++){
        ansarr[j++]=arr[i];
    }

    for(int i=0;i<n;i++){
        cout<<ansarr[i]<<" ";
    }
    return 0;
}