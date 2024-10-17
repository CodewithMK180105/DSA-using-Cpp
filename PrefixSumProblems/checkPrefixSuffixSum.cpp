// Given an array find the prefix sum array without creating new array

#include<iostream>
#include<vector>
using namespace std;
bool checkPrefixSuffixSum(vector<int> &v){
    int totalSum=0;
    int prefixSum=0;
    for(int i=0;i<v.size();i++) totalSum+=v[i];
    for(int i=0;i<v.size();i++){
        prefixSum+=v[i];
        int suffixSum=totalSum-prefixSum;
        if(prefixSum==suffixSum) return true;
    }
    return false;
}
int main(){
    vector<int> v;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int ele; cin>>ele;
        v.push_back(ele);
    }
    cout<<checkPrefixSuffixSum(v);
    return 0;
}