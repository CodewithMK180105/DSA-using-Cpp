// Check whether the given 2 strings are isomorphic or not.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isIsomorphic(string s1, string s2) {
    if(s1.size() != s2.size()){
        return false;
    }
    vector<int> v1(128,-1);
    vector<int> v2(128,-1);
    for(int i=0;i<s1.size();i++){
        if(v1[s1[i]] != v2[s2[i]]){
            return false;
        }
        v1[s1[i]]= v2[s2[i]]= i;
    }
    return true;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(isIsomorphic(s1,s2)){
        cout<<"Yes, the strings are isomorphic."<<endl;
    }else{
        cout<<"No, the strings are not isomorphic."<<endl;
    }
    return 0;
}
