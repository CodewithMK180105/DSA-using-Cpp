// Given an array of length N, find the length of the longest subarray with sum equal to 0.

// Hint: Use Prefix sum array.

#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

int longestSubarrayWithLengthZero(vector<int> v, int n){
    unordered_map<int,int> m;
    int maxLength=-1;
    int prefixSum=0;

    for(int i=0;i<n;i++){
        prefixSum+=v[i];
        if(prefixSum==0) maxLength=i+1; // Found a subarray with sum equal to 0.
        else if(m.find(prefixSum)!=m.end()){
            maxLength=max(maxLength,i-m[prefixSum]);
        }else {
            m[prefixSum]=i;
        }
    }
    return maxLength; // No subarray with sum equal to 0 found.
}

int main(){
    // vector<int> v={15, -2, 2, -8, 1, 7, 10, 23};
    vector<int> v={1,2,3};
    int n=v.size();
    cout<<longestSubarrayWithLengthZero(v,n)<<endl;
    return 0;
}