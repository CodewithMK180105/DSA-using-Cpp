#include<iostream>
#include<stack>
using namespace std;
int solve(char ch, int a, int b){
    if(ch=='+') return a+b;
    else if(ch=='-') return a-b;
    else if(ch=='*') return a*b;
    else if(ch=='/') return a/b;
}
int main(){
    string post="79+4*8/3-";
    stack<int> val;
    for(int i=0;i<post.length();i++){
        if(post[i]>=48 && post[i]<=57) val.push(post[i]-'0');
        else {
            int v2=val.top();
            val.pop();
            int v1=val.top();
            val.pop();
            int ans=solve(post[i], v1, v2);
            val.push(ans);
        }
    }
    cout<<val.top();
    return 0;
}