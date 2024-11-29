// A rotated sorted array in a sorted array on which rotation operation is performed som number of times. Given a sorted array find the index of the minimum element in the array. Followed 0-based indexing.

// It is guaranteed that elements in the array are unique.

// input: [3,4,5,1,2] output: 3

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
int main(){
    vector<int> input={4,5,1,2,3};
    cout<<searchMinimum(input);
    return 0;
}

