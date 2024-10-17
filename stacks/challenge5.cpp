// Insert at the index 'idx' in the stack using iterative method

#include<iostream>
#include<stack>
using namespace std;

void insert(stack<int> &input,int x,int idx){
    stack<int> temp;
    int n=input.size();
    int count=0;
    while(count<n-idx){
        count++;
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
    st.push(6);

    insert(st,10,3);

    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }

    return 0;
}