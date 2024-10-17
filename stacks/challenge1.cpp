// Copy elements of one stack to the another stack in same order using iterative method

#include<iostream>
#include<stack>
using namespace std;

stack<int> CopyElements(stack<int> &input){
    stack<int> temp;
    while(!input.empty()){
        int curr=input.top();
        input.pop();
        temp.push(curr);
    }
    stack<int> result;
    while(not temp.empty()){
        int curr=temp.top();
        temp.pop();
        result.push(curr);
    }
    return result;
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    stack<int> res=CopyElements(st);
    while(!res.empty()){
        cout<<res.top()<<" ";
        res.pop();
    }
    return 0;
}