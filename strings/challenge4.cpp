// Longest Common Prefix using the sorting method. O(n*lon(n)m)*n

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string longestCommonPrefix(vector<string> v){
    sort(v.begin(), v.end());
    string s1=v[0];
    int i=0;
    string s2=v[v.size()-1];
    int j=0;
    string result="";
    while(i<s1.size() && j<s2.size()){
        if(s1[i]==s2[j]){
            result+=s1[i];  // Add common character to the result string.
            i++; j++;
        }else{
            break;
        }
    }
    return   result;
}
int main(){
    vector<string> v = {"antic", "ant", "anti", "anthem"};
    cout<<longestCommonPrefix(v)<<endl;
    return 0;
}