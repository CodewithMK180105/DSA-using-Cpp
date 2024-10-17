#include<iostream>
using namespace std;
class Stack{
    public:
        int capacity;
        int* arr;
        int top;

        Stack(int c){
            capacity=c;
            arr=new int[c];
            top=-1;
        }

        void push(int val){
            if(this->top==this->capacity-1){
                cout<<"Overflow"<<endl;
                return;
            }
            top++;
            arr[top]=val;
            cout<<"Element added successfully"<<endl;
        }

        void pop(){
            if(top==-1){
                cout<<"Underflow"<<endl;
                return;
            }
            top--;
            cout<<"Element popped successfully"<<endl;
        }

        void topElement(){
            if(top==-1){
                cout<<"Underflow"<<endl;
                return;
            }
            cout<<"Top element is "<<arr[top]<<endl;
        }

        bool isEmpty(){
            return top==-1;
        }

        int size(){
            return top+1;
        }

        bool isFull(){
            return top==capacity-1;
        }

        void display(){
            if(top==-1){
                cout<<"Underflow";
                return;
            }
            for(int i=0;i<=top;i++) cout<<arr[i]<<" ";
            cout<<endl;
        }

};
int main(){

    Stack st1(3);
    st1.push(1);
    cout<<st1.size()<<endl;
    st1.push(2);
    st1.topElement();
    st1.push(3);
    cout<<st1.isEmpty()<<endl;
    cout<<st1.isFull()<<endl;
    st1.display();
    st1.push(4);
    st1.pop();
    st1.push(4);
    st1.push(5);
    st1.display();

    st1.pop();
    st1.pop();
    st1.pop();
    cout<<st1.isEmpty()<<endl;
    cout<<st1.isFull()<<endl;
    st1.display();

    return 0;
}