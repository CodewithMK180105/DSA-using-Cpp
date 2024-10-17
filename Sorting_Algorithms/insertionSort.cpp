#include<iostream>
#include<vector>
using namespace std;
void insertionSort(int n,vector<int> &v){
    for(int i=1;i<v.size();i++){
        int curr_element=v[i];
        int j=i-1;
        while(j>=0 && v[j]>curr_element){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=curr_element;
    }
}
int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    insertionSort(n,v);
    for(int i=0;i<n;i++) cout<<v[i]<<" ";
    return 0;
}