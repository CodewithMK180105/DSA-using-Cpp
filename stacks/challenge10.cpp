// Remove the element from any index of the stack using recursion

#include<iostream>
#include<stack>
using namespace std;

void removeFromAnyIndex(stack<int> &input,int idx){
    int n=input.size();
    int count=0;
    if(count==n-idx-1){
        input.pop();
        return;
    }
    int curr=input.top();
    input.pop();
    removeFromAnyIndex(input,idx);
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

    removeFromAnyIndex(st,2);

    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}