// Given the head of the sorted linkedlist , delete all duplicates such that element appears only once. Return the linkedlist sorted as well

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

void removeDuplicates(Node* &head){
    
    if(head==NULL || head->next==NULL) return;

    else{
        Node* temp= head;
        while(temp->next!=NULL){
            if(temp->val!=temp->next->val) temp=temp->next;
            else{
                Node* to_delete=temp->next;
                temp->next=temp->next->next;
                free(to_delete);
            }
        }
    }

}

int main(){
    
    LinkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(2);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(5);
    ll.insertAtTail(5);
    ll.insertAtTail(8);
    ll.display();
    
    removeDuplicates(ll.head);
    ll.display();
    
    return 0;
}