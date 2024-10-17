#include<iostream>
#include<vector>
using namespace std;
void selectionSort(int n,vector<int> &v){
    for(int i=0;i<v.size()-1;i++){
        int min_index=i;
        for(int j=i+1;j<v.size();j++){
            if(v[min_index]>v[j]) min_index=j;
        }
        if(min_index!=i) swap(v[min_index],v[i]);
    }
}
int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    selectionSort(n,v);
    for(int i=0;i<n;i++) cout<<v[i]<<" ";
    return 0;
}