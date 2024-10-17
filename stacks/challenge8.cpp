// Remove the bottom element from the stack using recursive function

#include<iostream>
#include<stack>
using namespace std;

void removeFromBottom(stack<int> &input){
    if(input.size()==1){
        input.pop();
        return;
    }
    int curr=input.top();
    input.pop();
    removeFromBottom(input);
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

    removeFromBottom(st);

    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}