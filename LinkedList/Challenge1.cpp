// Given the head of a linkedlist , delete every alternate element from the list starting from the second element

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

void deleteAlternateNodes(Node* &head){
    
    Node* temp= head;
    
    while(temp!=NULL && temp->next!=NULL){
        
        Node* to_delete=temp->next;
        
        temp->next=to_delete->next;
        
        free(to_delete);
        
        temp=temp->next;
        
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
    
    deleteAlternateNodes(ll.head);
    ll.display();
    
    return 0;
}