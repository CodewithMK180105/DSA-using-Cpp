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
            stack<int> temp;
            while(not st.empty()){
                temp.push(st.top());
                st.pop();
            }
            st.push(x);
            while(not temp.empty()){
                st.push(temp.top());
                temp.pop();
            }
        }

        void pop(){
            if(st.empty()) return;
            st.pop();
        }
        bool empty(){
            return st.empty();
        }
        int front(){
            return st.top();
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