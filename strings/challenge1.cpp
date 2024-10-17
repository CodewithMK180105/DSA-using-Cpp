// Sort the characters in a lexicographic order

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string countSort(string str){
    vector<int> v(26,0);
    for(char c: str) v[c-'a']++;
    // for(int c: v) cout<<c;
    string result="";
    for(int i=0;i<26;i++){
        while(v[i]--){
            result.push_back('a'+i);
        }
    }
    return result;
}
int main() {
    string str;
    cin>>str;
    cout<<countSort(str);
    return 0;
}