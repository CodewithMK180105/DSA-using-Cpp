// Given a mounted array of the length greater than 3, return the index 'i' such that arr[0]<arr[1]<...<arr[i-1]<arr[i]>arr[i+1]>...arr[arr.size()-1]. This is known as a peak index.

// Input: [0,4,1,0] ===> output: 1

// we noticed that 0 and n-1 cannot be our ans

#include<iostream>
#include<vector>
using namespace std;

int peakElement(vector<int> v){
    int low=1,high=v.size()-1,ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(v[mid-1]<v[mid]){
            ans=mid;
            low=mid+1;
        } else{
            high=mid-1;
        }
    }
    return ans;
}

int main(){
    int n; cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        v.push_back(x);
    }
    cout<<peakElement(v);
    return 0;
}