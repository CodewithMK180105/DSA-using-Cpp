// Find the minimum number of brackets that we need to remove to make the given bracket sequence balanced.
// Note: s contains only rounded paranthesis =>either '(' or ')'

#include<iostream>
#include<stack>
using namespace std;
int removeInvalidParentheses(string s){
    int n=s.length();
    stack<char> st;
    int count=0;

    for(int i=0;i<n;i++){
        if(')'==s[i] && st.empty()) count++;
        else if(')'==s[i] && !st.empty()) st.pop();
        else st.push(s[i]);
    }
    while(!st.empty()){
        count++;
        st.pop();
    }
    return count;
}
int main(){
    string s="(())())))";
    cout<<removeInvalidParentheses(s);
    return 0;
}