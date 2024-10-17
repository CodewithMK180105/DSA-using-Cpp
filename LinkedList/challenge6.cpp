// Given 2 heads of 2 LinkedList. Check whether both are equal or not.
// Two Linked List are called to be equal if they have same no. of elements, same data and same arrangement of the data.

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

bool checkEquality(Node* head1,Node* head2){
    Node *ptr1=head1;
    Node *ptr2=head2;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->val!=ptr2->val) return false;
        else{
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
    }
    if(ptr1!=NULL || ptr2!=NULL) return false;
    else return true;
}

int main(){
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    ll1.insertAtTail(6);
    ll1.insertAtTail(7);
    ll1.insertAtTail(8);
    ll1.display();
    
    LinkedList ll2;
    ll2.insertAtTail(1);
    ll2.insertAtTail(2);
    ll2.insertAtTail(3);
    ll2.insertAtTail(4);
    ll2.insertAtTail(5);
    ll2.insertAtTail(6);
    ll2.insertAtTail(7);
    ll2.insertAtTail(8);
    ll2.display();
    
    bool result=checkEquality(ll1.head,ll2.head);
    if(result) cout<<"Both the LinkLists are Equal";
    else cout<<"Both the LinkLists are not Equal";

    return 0;
}