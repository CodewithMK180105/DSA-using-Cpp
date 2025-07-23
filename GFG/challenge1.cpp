// Find minimum number of merge operations to make an array palindrome

#include<iostream>
#include<vector>
using namespace std;
int f(vector<int>& nums, int n){
    if(n==1) return 0;
    int count=0, l=0, r=n-1;

    while(l<r){
        if(nums[l]==nums[r]) {
            l++, r--;
        } else if(nums[l]<nums[r]){
            nums[l+1]+=nums[l];
            l++, count++;
        } else{
            nums[r-1]+=nums[r];
            r--, count++;
        }
    }
    return count;
}
int main(){
    vector<int> v={11,14,15,99};
    cout<<f(v,v.size());
    return 0;
}