#include<iostream>
using namespace std;
int main(){
    int arr[] = {2,3,1,3,2,4,1,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]) arr[i]=arr[j]=-1;
        }
    }
    for(int i=0;i<n;i++) if(arr[i]>0) cout<<arr[i]<<"  ";
    return 0;
}