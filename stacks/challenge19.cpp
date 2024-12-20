// Infix expression evaluation.

#include<iostream>
#include<stack>
#include<math.h>
#include<string>
using namespace std;
int calc(int m,int n,char operand){
    switch(operand){
        case '^': return pow(n,m);
        case '+': return n+m;
        case '-': return n-m;
        case '*': return n*m;
        case '/': return n/m;
        case '%': return n%m;
    }
}
int precedence(char c){
    if('^'==c) return 3;
    else if('*'==c || '/'==c) return 2;
    else if('+'==c || '-'==c) return 1;
    else return 0; 
}
int eval(string &s){
    stack<int> nums;
    stack<char> ops;
    int n=s.size();
    for(int i=0;i<n;i++){
        if (isspace(s[i])) continue; // Ignore spaces

        if(isdigit(s[i])){
            // nums.push(s[i]-'0');
            int num=0;
            while(i<n && isdigit(s[i])){
                num=num*10+(s[i]-'0');
                i++;
            }
            nums.push(num);
            i--;
        } else if('('==s[i]){
            ops.push(s[i]);
        } else if(')'==s[i]){
            while(!ops.empty() && ops.top()!='('){
                char op=ops.top();
                ops.pop();
                int a=nums.top();
                nums.pop();
                int b=nums.top();
                nums.pop();
                nums.push(calc(a,b,op));
            }
            if(!ops.empty()) ops.pop();
        } else{
            while(!ops.empty() && precedence(ops.top())>=precedence(s[i])){
                char op=ops.top();
                ops.pop();
                int a=nums.top();
                nums.pop();
                int b=nums.top();
                nums.pop();
                nums.push(calc(a,b,op));
            }
            ops.push(s[i]);
        }
    }
    return nums.top();
}
int main(){
    // string s="(1+(2*(3-1))+2)";
    string str="(2*(5*(3+6))/15-2)";
    cout<<eval(str);
    return 0;
}