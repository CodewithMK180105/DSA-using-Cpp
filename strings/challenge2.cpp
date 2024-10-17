// Anagrams

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool checkAnagram(string a, string b){
    vector<int> v(26,0);
    for(char c: a) v[c-'a']++;
    for(char c: b) v[c-'a']--;
    for(int i: v) if(i!=0) return false;
    return true;
}
int main(){
    string st1, st2;
    cin>>st1>>st2;
    cout<<checkAnagram(st1,st2);
    return 0;
}