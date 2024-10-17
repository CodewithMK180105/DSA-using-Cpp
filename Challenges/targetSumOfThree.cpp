#include<iostream>
using namespace std;
int main(){
    int arr[] = {3,1,2,4,0,6};
    int target,count=0;
    cin>>target;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==target) count++;
            }
        }
    }
    cout<<count;
    return 0;
}