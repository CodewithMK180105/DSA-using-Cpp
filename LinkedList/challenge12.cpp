// Given the head of a LinkedList Check whether it consists of a cycle or not.And remove the cycle if it is present.

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

bool checkCycle(Node* head){

    Node* slow_ptr=head;
    Node* fast_ptr=head;

    if(head==NULL) return false;

    while(fast_ptr && fast_ptr->next){

        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next->next;

        if(slow_ptr==fast_ptr){
            cout<<slow_ptr->val<<endl;
            return true;
        }

    }
    return false;
}

void removeCycle(Node* head){

    Node* slow_ptr=head;
    Node* fast_ptr=head;

    do{
        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next->next;
    }while(slow_ptr!=fast_ptr);

    fast_ptr=head;
    while(slow_ptr->next!=fast_ptr->next){
        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next;
    }

    slow_ptr->next=NULL;

}

int main(){
    LinkedList ll1;
    ll1.insertAtTail(3);
    ll1.insertAtTail(8);
    ll1.insertAtTail(14);
    ll1.insertAtTail(32);
    ll1.insertAtTail(39);
    ll1.insertAtTail(67);
    ll1.head->next->next->next->next->next->next=ll1.head->next->next->next;

    bool result=checkCycle(ll1.head);
    cout<<result<<endl;

    if(result) removeCycle(ll1.head);
    cout<<"After removing the Cycle : "<<endl;

    result=checkCycle(ll1.head);
    cout<<result<<endl;
    ll1.display();

    return 0;
}