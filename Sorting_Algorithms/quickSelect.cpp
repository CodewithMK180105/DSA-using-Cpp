// Find the kth smallest element in the array.

#include<iostream>
using namespace std;
int partition(int arr[], int stIdx, int endIdx){
    int pivotElement=arr[(stIdx+endIdx)/2];

    int smallElementCount=0;
    for(int i=stIdx;i<=endIdx;i++){
        if(i!=(stIdx+endIdx)/2 && arr[i]<=pivotElement){
            smallElementCount++;
        }
    }
    int pivotIdx=stIdx+smallElementCount;
    swap(arr[pivotIdx],arr[(stIdx+endIdx)/2]);

    int i=stIdx,j=endIdx;
    while(i<pivotIdx && j>pivotIdx){
        if(arr[i]<=pivotElement) i++;
        else if(arr[j]>pivotElement) j--;
        else if(arr[i]>pivotElement && arr[j]<pivotElement){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIdx;
}
int kthSmallest(int arr[], int stIdx, int endIdx, int k){
    int pivotIdx=partition(arr,stIdx,endIdx);
    if(pivotIdx+1==k) return arr[pivotIdx];
    else if(pivotIdx+1<k) return kthSmallest(arr,pivotIdx+1,endIdx,k);
    else return kthSmallest(arr,stIdx,pivotIdx-1,k);   
}
int main(){
    int arr[]={5,18,82,20,7,6,31,4,-8};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int k=4;
    cout<<kthSmallest(arr,0,n-1,k);
    
    return 0;
}