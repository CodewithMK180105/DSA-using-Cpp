// Given two heads of the linkedList. Check whether both the lists are intersecting or not.

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

int calculateLength(Node* head){
    Node* ptr=head;
    int length=0;
    while(ptr!=NULL){
        length++;
        ptr=ptr->next;
    }
    return length;
}

Node* moveHeadByKSteps(Node* head,int k){
    Node* temp=head;
    while(k--){
        temp=temp->next;
    }
    return temp;
}

Node* getIntersection(Node* head1, Node* head2){
    int l1=calculateLength(head1);
    int l2=calculateLength(head2);

    Node* ptr1;
    Node* ptr2;
    if(l1>l2){
        int k=l1-l2;
        ptr1=moveHeadByKSteps(head1,k);
        ptr2=head2;
    }
    else{
        int k=l2-l1;
        ptr2=moveHeadByKSteps(head2,k);
        ptr1=head1;
    }
    while(ptr1){
        if(ptr1==ptr2){
            return ptr1;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return NULL;
}

int main(){
    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    // 1->2->3->4->5->NULL
    ll1.display();
    
    LinkedList ll2;
    ll2.insertAtTail(6);
    ll2.insertAtTail(7);
    ll2.head->next->next=ll1.head->next->next->next;
    // 6->7->4->5->NULL
    ll2.display();
    
    Node* intersection=getIntersection(ll1.head,ll2.head);
    if(intersection) cout<<"The intersection point is "<<intersection->val<<endl;
    else cout<<"No intersection";

    return 0;
}