#include<iostream>
#include<stack>
using namespace std;
int main(){
    string post="79+4*8/3-";
    stack<string> val;
    for(int i=0;i<post.length();i++){
        if(post[i]>=48 && post[i]<=57) val.push(to_string(post[i]-'0'));
        else {
            string v2=val.top();
            val.pop();
            string v1=val.top();
            val.pop();
            string ans="("+v1+post[i]+v2+")";
            val.push(ans);
        }
    }
    cout<<val.top();
    return 0;
}