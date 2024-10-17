

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

bool isPalindrome(Node* head1){

    // 1. Find the middle element
    Node* slow_ptr=head1;
    Node* fast_ptr=head1;

    if(!head1 || !head1->next) return true;

    while(fast_ptr && fast_ptr->next){
        fast_ptr=fast_ptr->next->next;
        slow_ptr=slow_ptr->next;
    }

    // 2. Seperate the list into 2 lists
    Node* prev=slow_ptr;
    Node* curr=slow_ptr->next;
    slow_ptr->next=NULL;

    // 3. Reverse the second list

    while(curr){
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    // 4. Compare the elements of both the lists 
    // if the no of elements is odd then dont compare the last element of the first list

    Node* head2=prev;

    Node* ptr1=head1;
    Node* ptr2=head2;

    while(ptr2){
        if(ptr1->val!=ptr2->val) return false;

        ptr1=ptr1->next;
        ptr2=ptr2->next;

    }

    return true;

}

int main(){
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(3);
    ll1.insertAtTail(2);
    ll1.insertAtTail(1);
    ll1.display();

    cout<<isPalindrome(ll1.head);

    return 0;
}