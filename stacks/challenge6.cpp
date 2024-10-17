// Insert at the index 'idx' in the stack using recursive function

#include<iostream>
#include<stack>
using namespace std;

void insertAtAnyIndex(stack<int> &input,int x,int idx){
    int n=input.size();
    int count=0;
    if(count==n-idx){
        input.push(x);
        return;
    }
    int curr=input.top();
    input.pop();
    insertAtAnyIndex(input,x,idx);
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

    insertAtAnyIndex(st,10,3);

    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}