#include<iostream>
#include<stack>
using namespace std;
int main(){
    string pre="-/*+79483";
    stack<string> val;
    for(int i=pre.length()-1;i>=0;i--){
        if(pre[i]>=48 && pre[i]<=57) val.push(to_string(pre[i]-'0'));
        else {
            string v1=val.top();
            val.pop();
            string v2=val.top();
            val.pop();
            string ans="("+v1+pre[i]+v2+")";
            val.push(ans);
        }
    }
    cout<<val.top();
    return 0;
}