#include<iostream>
#include<vector>
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
    while(i<j){
        if(v[i]==1 && v[j]==0){
            v[i++]=0;
            v[j--]=1;
        }
        if(v[i]==0) i++;
        if(v[j]==1) j--;
    }
    for(int i=0;i<n;i++) cout<<v[i]<<" ";
    return 0;
}