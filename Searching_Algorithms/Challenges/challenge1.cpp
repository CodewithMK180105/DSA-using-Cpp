// Find the first occurrence of the given element x, given that the given element is sorted.
// If no occurrence is found then return -1;

#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> &v,int target){
    int ans=-1,low=0,high=v.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(v[mid]==target){
            ans=mid;
            high=mid-1;
        }
        else if(v[mid]<target) low=mid+1;
        else high=mid-1;
    }
    return ans;
}

int main(){
    vector<int> v={2,5,5,5,6,6,8,9,9,9};
    int target; cin>>target;
    if(search(v,target)==-1) cout<<"Element not Present";
    else cout<<"Element Present at the index "<<search(v,target);
    return 0;
}