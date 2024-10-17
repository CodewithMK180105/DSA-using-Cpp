#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void countSort(vector<int> &v){
    int max1=INT_MIN;
    // Finding the maximum element
    for(int i=0;i<v.size();i++){
        max1=max(max1,v[i]);
    }
    // Frequency of all the elements
    vector<int> freq(max1+1,0);
    for(int i=0;i<v.size();i++){
        freq[v[i]]++;
    }
    // Cumulative Frequency of all the elements
    for(int i=1;i<max1+1;i++){
        freq[i]+=freq[i-1];
    }
    vector<int> ans(v.size());
    for(int i=v.size()-1;i>=0;i--){
        ans[--freq[v[i]]]=v[i];
    }
    for(int i=v.size()-1;i>=0;i--){
        v[i]=ans[i];
    }
}
int main(){
    int n; cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++) cin>>v[i];
    countSort(v);
    for(int i=0;i<n;i++) cout<<v[i]<<" ";
    return 0;
}