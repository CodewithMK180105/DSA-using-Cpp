// Print all the possible Subsequences of the elements present in an array.

#include<iostream>
#include<vector>
using namespace std;
void printSubsequences(int arr[],int idx, int n, vector<int> v, int k){
    if(idx==n){
        if(v.size()==k){
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    if(v.size()+(n-idx)<k) return; // to avoid unnecessary calling
    printSubsequences(arr,idx+1,n,v,k);
    v.push_back(arr[idx]);
    printSubsequences(arr,idx+1,n,v,k);
}
int main(){
    int arr[]= {1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;

    vector<int> v;
    printSubsequences(arr,0,n,v,k);
    return 0;
}