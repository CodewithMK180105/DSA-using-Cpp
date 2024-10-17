// Check whether the given list is a palindrome or not

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

bool isPalindrome(Node* head,Node* tail){
    while(head!=tail && tail!=head->prev){
        if(head->val!=tail->val) return false;
        head=head->next;
        tail=tail->prev;
    }
    return true;
}

int main(){
    DoublyLL dll;
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.insertAtTail(3);
    dll.insertAtTail(3);
    dll.insertAtTail(2);
    dll.insertAtTail(1);

    dll.display();

    bool result=isPalindrome(dll.head,dll.tail);
    cout<<result;
    return 0;
}