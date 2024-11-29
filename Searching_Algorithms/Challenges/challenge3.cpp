// Given a sorted array of the integers. Find the first and the last position of the given 'target' element in the sorted array. Follow the 0-based indexing.
// If the element is not found return [-1,-1]

// eg: input: [1,2,3,3,3,5,11] and the target is 3 ==> output: [2,4].

#include<iostream>
#include<vector>
using namespace std;
int lowerBound(vector<int> v,int target){
    int lo=0,hi=v.size()-1,ans;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(v[mid]>=target){
            ans=mid;
            hi=mid-1;
        } else{
            lo=mid+1;
        }
    }
    return ans;
}
int upperBound(vector<int> v,int target){
    int lo=0,hi=v.size()-1,ans;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(v[mid]>target){
            ans=mid;
            hi=mid-1;
        } else{
            lo=mid+1;
        }
    }
    return ans-1;
}
int main(){
    int n; cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        v.push_back(x);
    }
    int target; cin>>target;
    int firstIdx=lowerBound(v,target);
    if(v[firstIdx]==target){    
        int secondIdx=upperBound(v,target);
        cout<<"["<<firstIdx<<","<<secondIdx<<"]";
    } else{
        cout<<"["<<-1<<","<<-1<<"]";
    }
    return 0;
}