// Evaluate the prefix operation.

#include<iostream>
#include<stack>
#include<string>
using namespace std;
int calc(int m,int n,char operand){
    switch(operand){
        case '+': return n+m;
        case '-': return n-m;
        case '*': return n*m;
        case '/': return n/m;
        case '%': return n%m;
    }
}
int evaluatePrefix(string s){
    int n=s.size();
    stack<int> st;

    for(int i=n-1;i>-1;i--){
        if('*'==s[i] || '/'==s[i] || '%'==s[i] || '+'==s[i] || '-'==s[i]){
            int a,b;
            if(!st.empty()){
                a=st.top();
                st.pop();
            }
            if(!st.empty()){
                b=st.top();
                st.pop();
            }
            else{
                cout<<"Invalid expression"<<endl;
                return 0;
            }
            int res=calc(a,b,s[i]);
            st.push(res);
        } else{
            st.push(s[i]-'0');
        }
    }
    int ans=st.top();
    st.pop();
    if(!st.empty()){
        cout<<"Invalid Expression"<<endl;
        return 0;
    }
    return ans;
}
int main(){
    string s="-9+*132";
    cout<<evaluatePrefix(s);
    return 0;
}