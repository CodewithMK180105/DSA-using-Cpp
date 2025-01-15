// Calculate the maximum sum of the subarray of the size k.

#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[]={7,1,2,5,8,4,9,3,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=4;
    int maxSum=INT_MIN;
    int prevSum=0;
    int minIdx=0;

    for(int i=0;i<k;i++){
        prevSum+=arr[i];
    }
    maxSum=prevSum;

    int i=1,j=k;
    while(j<n){
        int currSum=prevSum+arr[j]-arr[i-1];
        if(currSum>maxSum){
            maxSum=currSum;
            minIdx=i;
        }
        prevSum=currSum;
        i++;
        j++;
    }
    cout<<maxSum<<" "<<minIdx;
    return 0;
}