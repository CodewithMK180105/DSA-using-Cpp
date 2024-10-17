#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* prev;
        Node* next;

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

        void insertAtStart(int val){

            Node* new_node=new Node(val);

            if(head==NULL){
                head=new_node;
                tail=new_node;
                return;
            }
            new_node->next=head;
            head->prev=new_node;
            head=new_node;
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

        void insertAtKthPosition(int k,int val){

            if(k==1){
                insertAtStart(val);
                return;
            }

            Node * new_node=new Node(val);

            Node* ptr=head;

            int count=1;
            while(count!=k-1){
                ptr=ptr->next;
                count++;
            }

            new_node->prev=ptr;
            new_node->next=ptr->next;
            ptr->next->prev=new_node;
            ptr->next=new_node;

        }

        void deleteAtStart(){
            if(head==NULL) return;
            Node* to_delete=head;
            head=head->next;
            
            if(head==NULL) tail=NULL;

            else{
                head->prev=NULL;
            }
            free(to_delete);
        }

        void deleteAtEnd(){
            if(tail==NULL) return;

            Node* to_delete=tail;
            tail=tail->prev;

            if(tail==NULL) head=NULL;

            else{
                tail->next=NULL;
            }
            free(to_delete);
        }

        void deleteAtKthPosition(int k){
            if(head==NULL) return;
            else if(k==1){
                deleteAtStart();
                return;
            }
            else{
                Node* ptr=head;
                int count=1;
                while(count!=k-1){
                    ptr=ptr->next;
                    count++;
                }
                Node* to_delete=ptr->next;
                ptr->next=ptr->next->next;
                if(ptr->next!=NULL) ptr->next->prev=ptr;
                free(to_delete);
            }

        }

};

int main(){

    DoublyLL dll;

    dll.insertAtStart(1);
    // dll.display();
    // dll.deleteAtStart();
    // dll.display();
    // dll.display();
    // dll.deleteAtEnd();
    // dll.display();
    dll.insertAtStart(2);
    dll.insertAtStart(3);

    dll.insertAtTail(4);
    dll.insertAtTail(5);
    dll.insertAtTail(6);

    dll.display();

    // dll.insertAtKthPosition(2,8);
    // dll.insertAtKthPosition(5,11);
    // dll.insertAtKthPosition(8,17);
    // dll.insertAtKthPosition(1,17);

    // dll.deleteAtStart();
    // dll.deleteAtEnd();

    dll.deleteAtKthPosition(6);
    dll.display();

    return 0;
}