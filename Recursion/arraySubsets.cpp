// Print all the possible subsets of the elements present in an array.

#include<iostream>
#include<vector>
using namespace std;
void storeSubsets(int arr[],int idx, int n, vector<int> v){
    if(idx==n){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
    storeSubsets(arr,idx+1,n,v);
    v.push_back(arr[idx]);
    storeSubsets(arr,idx+1,n,v);
}
int main(){
    int arr[]= {1,2,3};
    int n=3;
    vector<int> v;
    storeSubsets(arr,0,n,v);
    return 0;
}