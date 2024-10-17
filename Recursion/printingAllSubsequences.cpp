// Printing all the possible subsequences
// Way : Here, we use the concept of taken and not taken
// eg  : a b c
//       0 0 0  ""
//       0 0 1  "c"
//       0 1 0  "b"
//       0 1 1  "bc"
//       1 0 0  "a"
//       1 0 1  "ac"
//       1 1 0  "ab"
//       1 1 1  "abc"

#include<iostream>
#include<vector>
using namespace std;
void subSequence(string &str,int i,string result,vector<string> &list){
    if(i==str.length()){
        list.push_back(result);
        return;
    }
    subSequence(str,i+1,result+str[i],list);
    subSequence(str,i+1,result,list);
}
int main(){
    string str="abc";
    vector<string> res;
    subSequence(str,0,"",res);
    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
    return 0;
}