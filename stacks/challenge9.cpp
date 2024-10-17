// Remove the element from any index of the stack using iterative method

#include<iostream>
#include<stack>
using namespace std;

void removeFromAnyIndex(stack<int> &input,int idx){
    int n=input.size();
    stack<int> temp;
    int count=0;
    while(count!=n-idx-1){
        count++;
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

    removeFromAnyIndex(st,3);

    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}