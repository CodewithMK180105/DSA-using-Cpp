// Given an integer array, in which all the 2 elements appears exactly once and rest all the elements appears exactly twice. Find the 2 usnique elements.

#include<iostream>
#include<vector>
using namespace std;
void findUnique(vector<int>& v, int n){
    int res=0;
    for(int i=0; i<n; i++) res^=v[i];
    int temp=res;
    int k=0;
    while(true){
        if(temp&1==1){
            break;
        }
        temp=temp>>1;
        k++;
    }

    int first=0;
    for(int i=0;i<n;i++){
        if((v[i]>>k)&1==1) first^=v[i];
    }
    int second=first^res;

    cout<<first<<" "<<second;
}
int main(){
    vector<int> v={1,2,1,3,2,5,5,9,8,8};
    findUnique(v, v.size());
    return 0;
}