// Remove all the occurrences of 'a'

#include<iostream>
using namespace std;
string f(string &s,int idx,int n){
    if(idx==n) return "";
    return (s[idx]=='a'?""+f(s,idx+1,n):s[idx]+f(s,idx+1,n));
}
int main(){
    string s="abcaxefag";
    int n=s.length();
    cout<<f(s,0,n);
    return 0;
}