// Print all the sub array of the given array.

#include<iostream>
#include<vector>
using namespace std;
void subArray(vector<int> v, int arr[], int n, int idx){
    if(idx==n){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
    subArray(v,arr,n,idx+1);   
    if(v.empty() || v.back()==arr[idx-1]){
        v.push_back(arr[idx]);
        subArray(v,arr,n,idx+1);
    }
}
int main(){
    int arr[]={1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         for(int k=i;k<=j;k++){
    //             cout<<arr[k]<<" ";
    //         }   
    //         cout<<endl;
    //     }
    // }
    vector<int> v;
    subArray(v,arr,n,0);
    return 0;
}