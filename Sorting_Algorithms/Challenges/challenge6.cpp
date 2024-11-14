// Push zeros to the end while maintaining the relative order of the other elements.

#include<iostream>
#include<string>
using namespace std;
int main(){
    int arr[]={5,0,1,2,0,0,4,0,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int nonZeroIndex=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            arr[nonZeroIndex]=arr[i];
            nonZeroIndex++;
        }
    }
    while(nonZeroIndex<n){
        arr[nonZeroIndex]=0;
        nonZeroIndex++;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}