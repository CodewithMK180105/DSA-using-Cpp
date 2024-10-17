// Given the head of a LinkedList find the middle node.
// Simplest approach count the no. of nodes by traversing the complete list.
// And then the (n/2)+1 th node will be the middle node
// Here we need to traverse the list 2 times

// But if we are told to traverse the list only once then,
// We can use slow and fast pointer approach.

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

class LinkedList{
public:
    Node* head;

    LinkedList(){
        head=NULL;
    }

    void insertAtTail(int val){

        Node* new_node=new Node(val);
        if(head==NULL){
            head=new_node;
            return;
        }

        else{
            Node* ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=new_node;
        }

    }

    void display(){
        Node* ptr=head;
        while(ptr!=NULL){
            cout<<ptr->val<<"->";
            ptr=ptr->next;
        } 
        cout<<"NULL"<<endl;
    }

};

Node* middleNode(Node* &head){
    Node* slow_ptr=head;
    Node* fast_ptr=head;
    while(fast_ptr!=NULL && fast_ptr->next!=NULL){
        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next->next;
    }
    return slow_ptr;
}

int main(){
    LinkedList ll1;
    ll1.insertAtTail(3);
    ll1.insertAtTail(8);
    ll1.insertAtTail(14);
    ll1.insertAtTail(32);
    ll1.insertAtTail(39);
    ll1.insertAtTail(67);
    
    ll1.display();

    Node* middle=middleNode(ll1.head);
    cout<<middle->val;

    return 0;
}