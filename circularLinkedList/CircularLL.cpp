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

class CircularLL{
    public:
        Node* head;
        CircularLL(){
            head=NULL;
        }
        void insertAtStart(int data){
            Node* new_node=new Node(data);
            if(head==NULL){
                head=new_node;
                new_node->next=head;
                return;
            }
            Node* tail=head;
            while(tail->next!=head){
                tail=tail->next;
            }
            new_node->next=head;
            head=new_node;
            tail->next=head;
        }
        void insertAtTail(int data){
            Node* new_node=new Node(data);
            if(head==NULL){
                head=new_node;
                new_node->next=head;
                return;
            }
            Node* ptr=head;
            while(ptr->next!=head){
                ptr=ptr->next;
            }
            ptr->next=new_node;
            new_node->next=head;
        }
        void deleteAtStart(){
            if(head==NULL) return;
            
            Node* ptr=head;
            Node* to_delete=head;
            if(head->next==head){
                head=NULL;
            }
            else{
                while(ptr->next!=head){
                    ptr=ptr->next;
                }
                ptr->next=head->next;
                head=head->next;
            }
            free(to_delete);
        }
        void deleteTail(){
            if(head==NULL) return;
            Node* ptr=head;
            if(head->next==head){
                head=NULL;
                return;
            }
            else{
                while(ptr->next->next!=head){
                    ptr=ptr->next;
                }
                Node* to_delete=ptr->next;
                ptr->next=head;
                free(to_delete);
            }
        }
        void display(){
            Node* ptr=head;
            do{
                cout<<ptr->val<<"->";
                ptr=ptr->next;
            }while(ptr!=head);
            cout<<"NULL"<<endl;
        }
};

int main(){
    CircularLL cll;
    cll.insertAtStart(5);
    cll.insertAtStart(4);
    cll.insertAtStart(3);
    cll.insertAtTail(8);
    cll.insertAtTail(9);


    cll.display();

    cll.deleteAtStart();
    cll.deleteAtStart();

    cll.display();

    cll.deleteTail();
    cll.deleteTail();

    cll.display();

}