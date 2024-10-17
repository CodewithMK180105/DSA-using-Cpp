// delete the nodes having the same neighbour. Traverse from the right to left

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

void deleteNodeHavingTheSameNeighbour(Node * tail){
    Node* ptr=tail->prev;
    while(ptr->prev!=NULL){
        if(ptr->prev->val==ptr->next->val){
            Node* temp=ptr;
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
        }
        ptr=ptr->prev;
    }
}

int main(){
    DoublyLL dll;
    dll.insertAtTail(2);
    dll.insertAtTail(1);
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.insertAtTail(1);

    dll.display();

    deleteNodeHavingTheSameNeighbour(dll.tail);
    dll.display();
    return 0;
}
