#include<iostream>
using namespace std;
int partition(int arr[], int startIdx, int endIdx){
    int pivotElement=arr[(startIdx+endIdx)/2];
    int smallElementCount=0;
    for(int i=startIdx;i<=endIdx;i++){
        if((startIdx+endIdx)/2==i) continue;
        if(pivotElement>=arr[i]){
            smallElementCount++;
        }
    }
    int pivotIdx=smallElementCount+startIdx;
    swap(arr[pivotIdx],arr[(startIdx+endIdx)/2]);

    int i=startIdx,j=endIdx;
    while(i<pivotIdx && j>pivotIdx){
        if(arr[i]<=pivotElement) i++;
        else if(arr[j]>pivotElement) j--;
        else if(arr[i]>pivotElement && arr[j]<=pivotElement){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivotIdx;
}
void quickSort(int arr[],int startIdx, int endIdx){
    if(startIdx>=endIdx) return;
    int pivotIdx=partition(arr,startIdx,endIdx);
    quickSort(arr,startIdx,pivotIdx-1);
    quickSort(arr,pivotIdx+1,endIdx);
}
int main(){
    int arr[]={5,1,8,2,7,6,3,4,-8};
    int n=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}