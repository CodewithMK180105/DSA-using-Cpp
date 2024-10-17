// Reverse the elements of the stack in the the same stack

// 1. Approach-1:- Original_stack => temp1_stack => temp2_stack => Original_stack

// 2. Recursion.

#include<iostream>
#include<stack>
using namespace std;

void insertUsingRecursion(stack<int> &input,int x){

    if(input.empty()){
        input.push(x);
        return;
    }
    
    int curr=input.top();
    input.pop();
    insertUsingRecursion(input,x);
    input.push(curr);
}

void reverseInOriginalStack(stack<int> &input){
    if(input.empty()){
        return;
    }
    int curr=input.top();
    input.pop();
    reverseInOriginalStack(input);
    insertUsingRecursion(input,curr);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    reverseInOriginalStack(st);

    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}