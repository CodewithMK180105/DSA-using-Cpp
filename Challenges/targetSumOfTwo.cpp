#include<iostream>
using namespace std;
int main(){
    int arr[] = {3,4,6,7,1};
    int target,count=0;
    cin>>target;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==target) count++; 
        }
    }
    cout<<count;
    return 0;
}