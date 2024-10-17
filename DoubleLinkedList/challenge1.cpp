// Reverse the given doubly LL

#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;

    Node(int data){
        val=data;
        prev=NULL;
        next=NULL;
    }

};

class DoublyLL{
    public:
        Node* head;
        Node* tail;

        DoublyLL(){
            head=NULL;
            tail=NULL;
        }

        void insertAtTail(int val){
            
            Node* new_node=new Node(val);

            if(tail==NULL){
                head=new_node;
                tail=new_node;
                return;
            }

            tail->next=new_node;
            new_node->prev=tail;
            tail=new_node;
            return;

        }

        void display(){
            if(head==NULL) cout<<"Nothing to display";
            else{
                Node *ptr=head;
                while(ptr){
                    cout<<ptr->val<<"<->";
                    ptr=ptr->next;
                }
                cout<<"NULL"<<endl;
            }
        }

};

void reverseList(Node* &head,Node* &tail){
    if(head==NULL || head->next==NULL) return;

    Node* currptr=head;

    while(currptr){
        Node* nextptr=currptr->next;
        currptr->next=currptr->prev;
        currptr->prev=nextptr;
        currptr=nextptr;
    }
    Node* new_head=tail;
    tail=head;
    head=new_head;
}

int main(){

    DoublyLL dll;
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.insertAtTail(3);
    dll.insertAtTail(4);

    dll.display();

    reverseList(dll.head,dll.tail);

    dll.display();

    return 0;
}