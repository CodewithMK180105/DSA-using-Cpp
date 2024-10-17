#include<iostream>
#include <climits>
using namespace std;
int main(){
    int arr[] = {1,8,9,4,6,3,9,7,2,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(max<arr[i]) max=arr[i];
    }
    int secondMax=INT_MIN;
    for(int i=0;i<n;i++){
        if(secondMax<arr[i] && arr[i]!=max) secondMax=arr[i];
    }
    cout<<"The 2nd maximum element of the array is "<<secondMax<<endl;
    return 0;
}