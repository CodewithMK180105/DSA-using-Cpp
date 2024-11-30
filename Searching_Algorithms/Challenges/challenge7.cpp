// Search element in a rotated sorted array with the duplicate elements. Return 1 if the element is found, else return 0.

// Input: [0,0,0,1,1,1,2,0,0,0] , target=2 ===> Output: 1

#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> nums, int target){
    int low=0,high=nums.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            return 1; // target element found
        }
        if(nums[low]==nums[mid] && nums[mid]==nums[high]){
            low++; high--;
        }
        else if(nums[low]<=nums[mid]){  // Left half is sorted
            if(nums[low]<=target && nums[mid]>target){
                high=mid-1;
            } else{
                low=mid+1;
            }
        }
        else{  // Right half is sorted
            if(nums[mid]<=target && nums[high]>=target){
                low=mid+1;
            } else{
                high=mid-1;
            }
        }
    }
    return 0;
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