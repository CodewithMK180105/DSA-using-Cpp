// Given the head of a LinkedList reverse the List, and return it.


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
        
        Node* new_node = new Node(val);
        
        if(head==NULL){
            head=new_node;
            return;
        }
        
        Node* temp=head;
        
        while(temp->next!=NULL){
            temp=temp->next;
        }
        
        temp->next=new_node;
        
    }
    
    void display(){
        
        Node* temp=head;
        
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        
        cout<<"NULL"<<endl;
        
    }
};

Node* reversedList(Node* &head){
    
    if(head==NULL || head->next==NULL) return head;

    else{
        Node* prev=NULL;
        Node* current=head;
        Node* ahead=head->next;

        while(current!=NULL){
            current->next=prev;
            prev=current;
            current=ahead;
            if(ahead!=NULL) ahead=ahead->next;
        }

        head=prev;

        return head;

    }
    
}
Node* reversedListUsingRecursion(Node* &head){
    
    if(head==NULL || head->next==NULL) return head;

    else{
        
        Node* new_head=reversedListUsingRecursion(head->next);
        head->next->next=head;
        head->next=NULL;
        return new_head;

    }
    
}

int main(){
    
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    ll.insertAtTail(7);
    ll.insertAtTail(8);
    ll.display();
    
    ll.head=reversedList(ll.head);
    ll.display();

    ll.head=reversedListUsingRecursion(ll.head);
    ll.display();
    
    return 0;
}