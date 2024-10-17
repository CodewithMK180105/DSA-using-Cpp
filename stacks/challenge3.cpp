// Insert at the bottom of the stack using iterative method

#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(int x,stack<int> &input){
    stack<int> temp;
    while(!input.empty()){
        int curr=input.top();
        input.pop();
        temp.push(curr);
    }
    input.push(x);
    while(!temp.empty()){
        int curr=temp.top();
        temp.pop();
        input.push(curr);
    }
}

int main(){

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    insertAtBottom(10,st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}