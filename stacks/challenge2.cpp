// Copy the elements of the one stack to the another stack using recursion in same order

#include<iostream>
#include<stack>
using namespace std;
void CopyUsingRecursion(stack<int> &input,stack<int> &result){
    
    if(input.empty()){
        return;
    }
    
    int curr=input.top();
    input.pop();
    CopyUsingRecursion(input,result);
    result.push(curr);
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    stack<int> res;
    CopyUsingRecursion(st,res);
    
    while(!res.empty()){
        cout<<res.top()<<endl;
        res.pop();
    }
    
    return 0;
}