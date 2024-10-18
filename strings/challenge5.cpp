// Longest Common Prefix without using the sorting method.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string longestCommonPrefix(vector<string> v){
    string str=v[0];
    int min_length=str.length();
    for(int i=1;i<v.size();i++){
        int j=0;
        while(j<str.length() && j<v[i].length() && str[j]==v[i][j]){
            j++;
        }
        min_length=min(min_length,j);
    }
    string ans=str.substr(0,min_length);
    return ans;
}
int main(){
    vector<string> v = {"antic", "an", "anti", "anthem"};
    cout<<longestCommonPrefix(v)<<endl;
    return 0;
}