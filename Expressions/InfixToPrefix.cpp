#include<iostream>
#include<stack>
using namespace std;
string eval(string s1, string s2, char ch){
    return ch+s1+s2;
}
int priority(char ch){
    if(ch=='*' || ch=='/') return 2;
    if(ch=='+' || ch=='-') return 1;
    return 0;
}
int main(){
    string s="2+6*4/8-3";
    stack<string> val;
    stack<char> op;

    for(int i=0;i<s.length();i++){
        if(s[i]>=48 && s[i]<=57) val.push(string(1, s[i]));
        else if(op.empty()) op.push(s[i]);
        else if(priority(op.top())<priority(s[i])) op.push(s[i]);
        else { // priority(op.top())>=priority(s[i])) op.push(s[i]
            while(priority(op.top())>=priority(s[i])){
                char ch=op.top();
                op.pop();
                string val2=val.top();
                val.pop();
                string val1=val.top();
                val.pop();
                string ans=eval(val1, val2, ch);
                val.push(ans);
            }
            op.push(s[i]);
        }
    }
    while(!op.empty()){
        char ch=op.top();
        op.pop();
        string val2=val.top();
        val.pop();
        string val1=val.top();
        val.pop();
        string ans=eval(val1, val2, ch);
        val.push(ans);
    }
    cout<<val.top();
    return 0;
}