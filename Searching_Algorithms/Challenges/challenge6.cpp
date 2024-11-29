// Given the rotated sorted array of integers which contains the distinct elements, and an integer target, return the index of the target if it is in the array. Otherwise return -1.

// input: [3,4,5,1,2], target= 4  ==> output: 1

// Using only 1 pass of the binary search TC: O(log n)

#include<iostream>
#include<vector>
using namespace std;
int search(vector<int> nums,int target){
    int low=0,high=nums.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]>=nums[low]){
            if(target>=nums[low] && target<=nums[mid]){
                high=mid-1;
            } else{
                low=mid+1;
            }
        } else{
            if(target<=nums[high] && target>=nums[mid]){
                low=mid+1;
            } else{
                high=mid-1;
            }
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
    int target; cin>>target;
    cout<<search(v,target);
    return 0;
}