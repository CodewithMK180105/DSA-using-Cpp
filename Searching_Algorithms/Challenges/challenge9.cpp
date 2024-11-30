// A peak element is an element that is strictly greater than it's neighbors. Given a 0-based indexing integer array nums, find the peak element, and return it's index. If the array contains multiple peaks, return the index to any peaks. You may imagine that nums[-1]=nums[n]=-infinity. In other words, an element is always considered to be strictly greater than the neighbor that is outside the array.

// Array: [1,2,1,2,6,10,3]
// Output: either 1 or it can be 5.

// Here we noticed that the value returned can be '0' or 'n-1'.

#include<iostream>
#include<vector>
using namespace std;
int findPeak(vector<int>& input){
    int n=input.size();
    int low=0,high=n-1,ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(mid==0){
            if(input[mid]>input[mid+1]) return 0;
            else return 1;
        } else if(mid==n-1){
            if(input[mid]>input[mid-1]) return n-1;
            else n-2;
        } else{
            if(input[mid-1]<input[mid] && input[mid]>input[mid+1]) return mid;
            else if(input[mid-1]<input[mid]) low=mid+1;
            else high=mid-1;
        }
    }
    return -1;
}
int main(){
    int n; cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        v.push_back(x);
    }
    cout<<findPeak(v);
    return 0;
}