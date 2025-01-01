// Print all the possible subsets of a string.

#include<iostream>
#include<string>
#include<vector>
using namespace std;
void printSubsets(string subset, string original, int idx){
    if(idx==original.length()){
        cout<<subset<<endl;
        return;
    }
    printSubsets(subset+original[idx],original,idx+1);
    printSubsets(subset,original,idx+1);
}
void printSubsets2(string subset, string original){
    if(original==""){
        cout<<subset<<endl;
        return;
    }
    char ch=original[0];
    printSubsets2(subset+ch,original.substr(1));
    printSubsets2(subset,original.substr(1));
}
void storeSubsets(string subset, string original, int idx, vector<string>& v){
    if(idx==original.length()){
        v.push_back(subset);
        return;
    }
    storeSubsets(subset+original[idx],original,idx+1,v);
    storeSubsets(subset,original,idx+1,v);
}
int main(){
    printSubsets("","abc",0);
    cout<<"Part-2"<<endl;
    printSubsets2("","abc");
    cout<<"Part-3"<<endl;

    vector<string> v;
    storeSubsets("","abc",0,v);
    for(string st: v){
        cout<<st<<" ";
    }
}