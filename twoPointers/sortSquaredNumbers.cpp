// Given an integer array 'a' sorted in non-decreasing order, return an array of
// the squares of each number sorted in non-decreasing order.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int ele; cin>>ele;
        v.push_back(ele);
    }
    int i=0,j=n-1;
    vector<int> ansvec;
    while(i<=j){
        if(abs(v[i])>abs(v[j])){
            ansvec.push_back(v[i]*v[i]);
            i++;
        }
        else{
            ansvec.push_back(v[j]*v[j]);
            j--;
        }
    }
    reverse(ansvec.begin(),ansvec.end());
    for(int i=0;i<n;i++) cout<<ansvec[i]<<" ";
    return 0;
}