#include<iostream>
#include <climits>
using namespace std;
int indexOfLargestElement(int arr[],int n){
    int max=INT_MIN,maxIndex;
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
            maxIndex=i;
        }
    }
    return maxIndex;
}
int main(){
    int arr[] = {1,8,9,4,6,3,9,7,2,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int index=indexOfLargestElement(arr,n);
    int max=arr[index];
    for(int i=0;i<n;i++){
        if(max==arr[i]) arr[i]=INT_MIN;   
    }
    int finalIndex=indexOfLargestElement(arr,n);
    cout<<"The 2nd maximum element of the array is "<<arr[finalIndex]<<" which is at the position "<<finalIndex+1<<endl;
    return 0;
}