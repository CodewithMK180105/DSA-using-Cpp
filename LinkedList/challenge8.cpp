// Given the head of the linked list, remove the k-th node from the the end of the list.
// And return the head

// The simplest approach is calculate the leng(n) of the list by traversing the complete list
// and then delete the (n-k+1)th node from start.
// Here we traverse the list 2 times.

// But if we are asked to traverse the list only once,
// We can use 2 pointers whose difference will be k nodes

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

void deleteKthLastNode(Node* &head,int k){
    Node* ptr1=head;
    Node* ptr2=head;

    while(k--){
        ptr2=ptr2->next;
    }

    if(ptr2==NULL){
        Node* to_delete=head;
        head=head->next;
        free(to_delete);
        return;
    }

    while(ptr2->next!=NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    Node* to_delete=ptr1->next;
    ptr1->next=ptr1->next->next;
    free(to_delete);
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

    deleteKthLastNode(ll1.head,8);
    ll1.display();

    return 0;
}