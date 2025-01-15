// Check if an array can be partitioned into two continuous arrays of equal sum.

#include<iostream>
using namespace std;
int main(){
    int arr[]={2,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=1;i<n;i++){
        arr[i]+=arr[i-1];
    }

    int idx=-1;
    for(int i=0;i<n;i++){
        if(2*arr[i]==arr[n-1]){
            idx=i;
            break;
        }
    }

    if(idx!=-1) cout<<"Yes the partition is possible with index as "<<idx;
    else cout<<"No, The partition is not possible";
    return 0;
}