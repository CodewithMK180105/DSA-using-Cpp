// We are given a queue data structure with push and pop operations, the task is to implement a stack using instances of stack data structure and perform operations on them.
// we have 2 options:-
// 1. push effieient: push complexity O(1) pop efficient O(n)
// 2. pop effieient: push complexity O(n) pop efficient O(1)

#include<iostream>
#include<queue>
using namespace std;

class Stack{
    public:
        Stack(){}

        queue<int> qu;

        void push(int x){
            queue<int> temp;
            while(!qu.empty()){
                temp.push(qu.front());
                qu.pop();
            }
            qu.push(x);
            while(!temp.empty()){
                qu.push(temp.front());
                temp.pop();
            }
        }

        void pop(){
            qu.pop();
        }

        int front(){
            return qu.front();
        }

        bool isEmpty(){
            return qu.empty();
        }

};

int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.pop();
    st.push(40);
    st.pop();

    while(!st.isEmpty()){
        cout<<st.front()<<" ";
        st.pop();
    }
    return 0;
}