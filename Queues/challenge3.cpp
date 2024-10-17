// We are given a stack data structure with push and pop operations, the task is to implement a queue using instances of stack data structure and perform operations on them.
// we have 2 options:-
// 1. push effieient: push complexity O(1) pop efficient O(n)
// 2. pop effieient: push complexity O(n) pop efficient O(1)


#include<iostream>
#include<stack>
using namespace std;

class Queue{
    public:
        stack<int> st;

        Queue(){}

        void push(int x){
            st.push(x);
        }

        void pop(){
            if(st.empty()) return;
            stack<int> temp;
            while(st.size()>1){
                temp.push(st.top());
                st.pop();
            }
            st.pop();
            while(not temp.empty()){
                st.push(temp.top());
                temp.pop();
            }
        }
        bool empty(){
            return st.empty();
        }
        int front(){
            if(st.empty()) return -1;
            stack<int> temp;
            while(st.size()>1){
                temp.push(st.top());
                st.pop();
            }
            int res=st.top();
            while(not temp.empty()){
                st.push(temp.top());
                temp.pop();
            }
            return res;
        }
};

int main(){
    Queue qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);
    qu.pop();
    qu.pop();
    while(not qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }
    return 0;
}