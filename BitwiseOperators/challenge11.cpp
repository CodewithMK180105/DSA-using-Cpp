// Given an integer array. Find the length of the longest subarray which has the maximum possible bitwise AND value.

#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v={12,13,1,6,1,6,6,6,16,4,3,8,13,13,13,8};
    int n=v.size();
    int mx=v[0];
    int i=0,j=1;
    int maxLen=0;
    while(j<n){
        if(v[j]>mx){
            i=j;
            while(j<n && v[j]==v[i]){
                j++;
            }
            mx=v[i];
            maxLen=j-i;
        } else if(v[j]==mx){
            i=j;
            while(j<n && v[j]==v[i]){
                j++;
            }
            maxLen=max(maxLen, j-i);
        } else j++;
    }
    cout<<maxLen;
    return 0;
}