#include<iostream>
using namespace std;
int main(){
    int arr[]={4,1,6,2,5,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int i=0;
    while(i<n){
        if(arr[i]-1!=i){
            swap(arr[i],arr[arr[i]-1]);
        } else{
            i++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}