// Desighn a stack to support push,pop,top, and retrieving the minimum element in the constant time.

// Implement the minstack class:
// a. MinStack Initializes the stack object.
// b. void push(int val) push the element val into the stack.
// c. void pop() removes the element on the top of the stack.
// d. int getMin() retrieves the minimum element in the stack.

// You must implement the solution with the O(1) time complexity for the each function.
// Assumption: Methods: pop, top, and getMin operations will always be called on a non-empty stack.

#include<iostream>
#include<stack>
using namespace std;
class Stack{
public:
    stack<int> st;
    stack<int> minSt;
    Stack(){
        
    }
    void push(int val){
        if(st.empty()){
            minSt.push(val);
            st.push(val);
        } else{
            if(val<=minSt.top()){
                minSt.push(val);
            }
            st.push(val);
        }
        cout<<"Element pushed successfully"<<endl;
    }
    
    void pop(){
        if(st.top()==minSt.top()) minSt.pop();
        st.pop();
    }

    int top(){
        return st.top();
    }
    
    int getMin(){
        return minSt.top();
    }
};
int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(5);
    st.push(15);

    cout << "Minimum Element: " << st.getMin() << endl;

    st.pop();
    cout << "Top Element after pop: " << st.top() << endl;
    cout << "Minimum Element: " << st.getMin() << endl;

    return 0;

}