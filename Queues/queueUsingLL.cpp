#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            data=val;
            next=NULL;
        }
};

class Queue{
    public:
        Node* head;
        Node* tail;
        int size;

        Queue(){
            head=NULL;
            tail=NULL;
            size=0;
        }

        void enque(int data){
            Node* new_node =new Node(data);
            if(head==NULL){
                head=tail=new_node;
            }
            else{
                tail->next=new_node;
                tail=new_node;
            }
            size++;
        }

        void dequeue(){
            if(head==NULL){
                return;
            }
            Node* to_delete=head;
            head=head->next;
            if(head==NULL) tail=NULL;
            free(to_delete);
            size--;
        }

        int getSize(){
            return size;
        }
        
        bool isEmpty(){
            return head==NULL;
        }

        int front(){
            if(head==NULL) return -1;
            else return head->data;
        }
};

int main(){
    Queue qu;
    qu.enque(10);
    qu.enque(20);
    qu.enque(30);
    qu.dequeue();
    qu.enque(40);
    while(not qu.isEmpty()){
        cout<<qu.front()<<" ";
        qu.dequeue();
    }
    return 0;
}