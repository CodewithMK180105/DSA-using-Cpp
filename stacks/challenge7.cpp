// Remove the bottom element from the stack using iterative method

#include<iostream>
#include<stack>
using namespace std;

void removeFromBottom(stack<int> &input){
    stack<int> temp;
    while(input.size()!=1){
        int curr=input.top();
        input.pop();
        temp.push(curr);
    }
    input.pop();
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
    st.push(6);

    removeFromBottom(st);

    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}