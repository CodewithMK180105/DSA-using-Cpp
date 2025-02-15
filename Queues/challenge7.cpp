// Reverse the first k elements of the queue.

#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void reversefirstKElements(queue<int>& q, int k){
    stack<int> st;
    for(int i=0;i<k;i++){
        st.push(q.front());
        q.pop();
    }
    for(int i=0;i<k;i++){
        q.push(st.top());
        st.pop();
    }
    int remaining=q.size()-k;
    for(int i=0;i<remaining;i++){
        int front=q.front();
        q.pop();
        q.push(front);
    }
}
void display(queue<int>& q){
    for(int i=0;i<q.size();i++){
        int front=q.front();
        cout<<front<<" ";
        q.pop();
        q.push(front);
    }
    cout<<endl;
}
int main(){
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);

    display(q);

    reversefirstKElements(q,3);

    display(q);

    return 0;
}