// We are given two sorted LinkedList, merge them into 1 List so that the resultant List is also sorted

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

Node* merge(Node* ptr1,Node* ptr2){
    Node* dummyHead=new Node(-1);
    Node* ptr3=dummyHead;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->val<ptr2->val){
            ptr3->next=ptr1;
            ptr1=ptr1->next;    
        }
        else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
    if(ptr1) ptr3->next=ptr1;
    if(ptr2) ptr3->next=ptr2;

    return dummyHead->next;
}

int main(){
    LinkedList ll1;
    ll1.insertAtTail(3);
    ll1.insertAtTail(8);
    ll1.insertAtTail(14);
    ll1.insertAtTail(32);
    ll1.insertAtTail(39);
    ll1.insertAtTail(67);
    
    LinkedList ll2;
    ll2.insertAtTail(1);
    ll2.insertAtTail(4);
    ll2.insertAtTail(24);
    ll2.insertAtTail(35);
    ll2.insertAtTail(43);
    ll2.insertAtTail(76);
    
    LinkedList ll3;
    ll3.head=merge(ll1.head,ll2.head);
    ll3.display();

    return 0;
}