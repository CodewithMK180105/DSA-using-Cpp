// Find the kth largest element in the array.

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
int kthlargest(int arr[], int stIdx, int endIdx, int k, int n){
    int pivotIdx=partition(arr,stIdx,endIdx);
    if(n-pivotIdx==k) return arr[pivotIdx];
    else if(n-pivotIdx>k) return kthlargest(arr,pivotIdx+1,endIdx,k,n);
    else return kthlargest(arr,stIdx,pivotIdx-1,k,n);
}
int main(){
    int arr[]={3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int k=2;
    cout<<kthlargest(arr,0,n-1,k,n);
    
    return 0;
}