// Insert the element at the bottom of the stack using recursive function

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
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    insertUsingRecursion(st,1000);
    
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    
    return 0;
}