#include<iostream>
#include<stack>
using namespace std;
int priority(char ch){
    switch(ch){
        case '/': return 2;
        case '*': return 2;
        case '+': return 1;
        case '-': return 1;
    }
    return 0;
}
int main(){
    string s="(7+9)*4/8-3";
    stack<string> val;
    stack<char> op;
    for(int i=0;i<s.length();i++){
        if(s[i]>=48 && s[i]<=57){
            val.push(to_string(s[i]-'0'));
        } else if(op.empty()){
            op.push(s[i]);
        } else if(s[i]=='('){
            op.push(s[i]);
        } else if(s[i]==')'){
            while(op.top()!='('){
                char ch=op.top();
                op.pop();
                string val2=val.top();
                val.pop();
                string val1=val.top();
                val.pop();
                string ans=(val1+val2+ch);
                val.push(ans);
            }
            op.pop(); // opening bracket ko bhi udaado
        } else if(priority(op.top())<priority(s[i])){
            op.push(s[i]);
        } else {
            while(!op.empty() && priority(op.top())>=priority(s[i])){
                char ch=op.top();
                op.pop();
                string val2=val.top();
                val.pop();
                string val1=val.top();
                val.pop();
                string ans=(val1+val2+ch);
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
        string ans=(val1+val2+ch);
        val.push(ans);
    }
    cout<<val.top();
    return 0;
}