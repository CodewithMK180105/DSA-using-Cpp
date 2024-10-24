// Check whether the strings are isomorphic or not.

#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

bool checkMapping(string s1,string s2) {
    unordered_map<char,char> mapping;
    for(int i=0;i<s1.length();i++){
        if(mapping.find(s1[i])!=mapping.end()){
            if(mapping[s1[i]]!=s2[i]) return false;
        }
        else mapping[s1[i]] = s2[i];
    }
    return true;
}

bool isIsomorphic(string s1, string s2) {

    if(s1.length() != s2.length()){
        return false;
    }

    bool s1s2=checkMapping(s1, s2);
    bool s2s1=checkMapping(s2, s1);

    return s1s2 && s2s1;
}

int main() {
    string str1,str2;
    cin >> str1 >> str2;
    cout<<isIsomorphic(str1,str2);
    return 0;
}