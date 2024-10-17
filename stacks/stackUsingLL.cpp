#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node(int data){
            val=data;
            next=NULL;
        }
};

class Stack{

    public:

    Node* head;
    int currSize;

    Stack(){
        head=NULL;
        currSize=0;
    }

    bool isEmpty(){
        return head==NULL;
    }

    void push(int data){
        Node* new_node=new Node(data);
        new_node->next=head;
        head=new_node;
        currSize++;
        cout<<"New Node added successfully"<<endl;
    }

    void pop(){
        if(head==NULL){
            cout<<"Underflow"<<endl;
            return;
        }
        Node* to_delete=head;
        head=head->next;
        free(to_delete);
        currSize--;
        cout<<"Node popped successfully"<<endl;
    }

    int size(){
        return currSize;
    }

    void getTop(){
        if(head==NULL){
            cout<<"Underflow"<<endl;
            return;
        }
        cout<<head->val<<endl;
    }
    
    void display(){
        if(head==NULL){
            cout<<"Underflow"<<endl;
            return;
        } 
        Node* ptr=head;
        while(ptr!=NULL){
            cout<<ptr->val<<" ";
            ptr=ptr->next;
        }cout<<endl;
    }

};

int main(){
    Stack st;
    cout<<st.isEmpty()<<endl;
    cout<<st.size()<<endl;
    st.display();
    st.getTop();
    st.push(1);
    st.push(2);
    st.push(5);
    cout<<st.isEmpty()<<endl;
    cout<<st.size()<<endl;
    st.getTop();
    st.display();
    st.pop();
    st.display();
    st.getTop();
    return 0;
}