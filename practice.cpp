#include<iostream>
using namespace std;
int partition(int arr[], int stIdx, int endIdx){
    int pivotElement=arr[endIdx];
    int i=stIdx-1;
    for(int j=stIdx;j<endIdx;j++){
        if(arr[j]<pivotElement){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[endIdx]);
    return i;
}
int quickSelect(int arr[], int stIdx, int endIdx,int k){
    int pivotIdx=partition(arr,stIdx,endIdx);
    if(pivotIdx+1==k) return arr[pivotIdx];
    if(pivotIdx+1>k) return quickSelect(arr,stIdx,pivotIdx-1,k);
    else return quickSelect(arr,pivotIdx+1,endIdx,k);
}
int main(){
    int arr[]={7,2,45,1,9,3,8,55,42};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    } cout<<endl;
    int k=3;
    cout<<quickSelect(arr,0,n-1,k);
    return 0;
}