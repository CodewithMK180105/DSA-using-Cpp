// Given an integer array arr, move all 0's to the end of it while maintaining 
// the relative order of the non-zero elements

// Note:You must do this in-place without making a copy of the array.

#include<iostream>
#include<vector>
using namespace std;
void sort(vector<int> &v){
    for(int i=0;i<v.size();i++){
        int j=i;
        bool flag=false;
        while(j<v.size()-1){
            if(v[j+1]!=0 && v[j]==0){
                flag=true;
                swap(v[j+1],v[j]);
            }
            j++;
        }
        if(!flag) break;
    }
}
int main(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}