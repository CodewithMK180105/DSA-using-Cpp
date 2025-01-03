// Print all the permutations of the characters present in a string.

#include<iostream>
#include<vector>
using namespace std;
void printPermutations(string ans, string original){
    if(original==""){
        cout<<ans<<" ";
        return;
    }
    for(int i=0;i<original.length();i++){
        char ch=original[i];
        string left=original.substr(0,i);
        string right=original.substr(i+1);
        printPermutations(ans+ch,left+right);
    }
}
void storePermutations(string ans, string original, vector<string>& result){
    if(original==""){
        result.push_back(ans);
        return;
    }
    for(int i=0;i<original.length();i++){
        char ch=original[i];
        string left=original.substr(0,i);
        string right=original.substr(i+1);
        storePermutations(ans+ch,left+right,result);
    }
}
int main(){
    string str="abc";
    printPermutations("", str);
    cout<<endl;

    string s="xyz";
    vector<string> res;
    storePermutations("",s,res);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}