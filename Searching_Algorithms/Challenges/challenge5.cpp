// Given the rotated sorted array of integers which contains the distinct elements, and an integer target, return the index of the target if it is in the array. Otherwise return -1.

// input: [3,4,5,1,2], target= 4  ==> output: 1

// Using the 3 pass of binary search TC: O(3*log n)

#include<iostream>
#include<vector>
using namespace std;
int searchMinimum(vector<int> input){
    int low=0,high=input.size()-1;
    if(input[low]<input[high]) return low;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(input[mid+1]<input[mid]) return mid+1;
        if(input[mid]<input[mid-1]) return mid;
        if(input[mid]>input[low]) low=mid+1;
        else if(input[mid]<input[low]) high=mid-1;
    }
    return -1;
}

int binarySearch(vector<int> v,int target,int start,int end){
    int low=start,high=end;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(v[mid]==target){
            return mid;
        } else if(v[mid]<target){
            low=mid+1;
        } else{
            high=mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> input={4,5,1,2,3};
    int target; cin>>target;
    int partition=searchMinimum(input);
    if(input[partition]==target) cout<<partition;
    else{
        int a=binarySearch(input,target,0,partition-1);
        if(a==-1){
            int b=binarySearch(input,target,partition+1,input.size()-1);
            cout<<b;
            return 0;
        }
        cout<<a;
    }
    return 0;
}