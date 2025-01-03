// Print all the possible subsets of the elements present in an array.

#include<iostream>
#include<vector>
using namespace std;
void printSubsets(int arr[],int idx, int n, vector<int> v){
    if(idx==n){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
    printSubsets(arr,idx+1,n,v);
    v.push_back(arr[idx]);
    printSubsets(arr,idx+1,n,v);
}
int main(){
    int arr[]= {1,2,3};
    int n=3;
    vector<int> v;
    printSubsets(arr,0,n,v);
    return 0;
}