#include<iostream>
#include<stack>
using namespace std;
int solve(char ch, int a, int b){
    if(ch=='+') return a+b;
    else if(ch=='-') return a-b;
    else if(ch=='/') return a/b;
    else if(ch=='*') return a*b;
    return 0;
}
int main(){
    string pre="-/*+79483";
    stack<int> val;
    for(int i=pre.length()-1;i>=0;i--){
        if(pre[i]>=48 && pre[i]<=57) val.push(pre[i]-'0');
        else {
            int v1=val.top();
            val.pop();
            int v2=val.top();
            val.pop();
            int ans=solve(pre[i],v1,v2);
            val.push(ans);
        }
    }
    cout<<val.top();
    return 0;
}