// Calculate the maximum sum of the subarray of the size k.

#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[]={7,1,2,5,8,4,9,3,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    int maxSum=INT_MIN;
    int minIdx=-1;

    for(int i=0;i<=n-k;i++){
        int currSum=0;
        for(int j=i;j<=i+k-1;j++){
            currSum+=arr[j];
        }
        if(currSum>maxSum){
            minIdx=i;
            maxSum=currSum;
        }
    }

    cout<<maxSum<<" "<<minIdx;
    return 0;
}