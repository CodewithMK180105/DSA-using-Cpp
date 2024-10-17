#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void countSort(vector<int> &v,int pos){
    vector<int> freq(10,0);
    for(int i=0;i<v.size();i++) freq[(v[i]/pos)%10]++;
    for(int i=1;i<freq.size();i++) freq[i]+=freq[i-1];
    vector<int> ans(v.size());
    for(int i=v.size()-1;i>=0;i--) ans[--freq[(v[i]/pos)%10]]=v[i];
    for(int i=v.size()-1;i>=0;i--) v[i]=ans[i];
}
void radixSort(vector<int> &v){
    int max_ele=INT_MIN;
    for(int i=0;i<v.size();i++) max_ele=max(max_ele,v[i]);
    for(int pos=1;max_ele/pos>0;pos*=10) countSort(v,pos);  
}
int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    radixSort(v);
    for(int i=0;i<n;i++) cout<<v[i]<<" ";
    return 0;
}