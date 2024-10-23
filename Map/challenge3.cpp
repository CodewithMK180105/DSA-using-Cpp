// Check whether the two strings are anagram of each other or not.

#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;
bool anagrams(string a, string b){
    if(a.length()!=b.length()) return false;

    unordered_map<char,int> charCount;
    for(char c: a) charCount[c]++;
    for(char c: b) {
        if(charCount.find(c)==charCount.end()) return false;
        charCount[c]--;
    }
    for(auto c: charCount) if(c.second!=0) return false;
    return true;
}
int main(){
    string str1, str2;
    cin>>str1>>str2;
    cout<<(anagrams(str1,str2)?"Yes":"No")<<endl;
    return 0;
}