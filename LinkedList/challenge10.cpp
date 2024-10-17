// We are given two sorted LinkedList, merge them into 1 List so that the resultant List is also sorted

#include<iostream>
#include<vector>
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

// Approach:-
// vector -> head1 head2 head3 head4
// 1. head1 and head2 will be merged
// vector -> head3 head4 mergedhead1_2
// 2. head3 and head4 will be merged
// vector -> mergedhead1_2 mergedhead3_4
// 3. mergedhead1_2 and mergedhead3_4 will be merged
// vector -> mergedhead1_2_3_4

Node* mergeKLists(vector<Node*> &list){

    if(list.size()==0) return NULL;
    
    while(list.size()>1){
        Node* mergedHead=merge(list[0],list[1]);
        list.push_back(mergedHead);
        list.erase(list.begin());
        list.erase(list.begin());
    }

    return list[0];

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
    ll3.insertAtTail(7);
    ll3.insertAtTail(10);
    ll3.insertAtTail(12);
    ll3.insertAtTail(42);
    ll3.insertAtTail(83);
    ll3.insertAtTail(176);
    
    LinkedList ll4;
    ll4.insertAtTail(4);
    ll4.insertAtTail(8);
    ll4.insertAtTail(14);
    ll4.insertAtTail(31);
    ll4.insertAtTail(46);
    ll4.insertAtTail(79);

    vector<Node* > v;
    v.push_back(ll1.head);
    v.push_back(ll2.head);
    v.push_back(ll3.head);
    v.push_back(ll4.head);

    LinkedList ll5;
    ll5.head=mergeKLists(v);
    ll5.display();

    return 0;
}