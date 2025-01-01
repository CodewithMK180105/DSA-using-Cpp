// Find all the subsets of characters in a string with the duplicates.

#include<iostream>
#include<string>
#include<vector>
using namespace std;
void storeSubsets(string subset, string original, int idx, vector<string>& v, bool flag){
    if(idx==original.length()){
        v.push_back(subset);
        return;
    }
    if(idx==original.length()-1){
        if(flag) storeSubsets(subset+original[idx],original,idx+1,v,true);
        storeSubsets(subset,original,idx+1,v,true);
        return;
    }
    char ch=original[idx];
    char dh=original[idx+1];
    if(ch==dh){
        if(flag) storeSubsets(subset+original[idx],original,idx+1,v,true);
        storeSubsets(subset,original,idx+1,v,false);
    } else{
        if(flag) storeSubsets(subset+original[idx],original,idx+1,v,true);
        storeSubsets(subset,original,idx+1,v,true);
    }
}
int main(){
    vector<string> v;
    string str="aab";
    storeSubsets("",str,0,v,true);
    for(string st: v){
        cout<<st<<" ";
    }
}