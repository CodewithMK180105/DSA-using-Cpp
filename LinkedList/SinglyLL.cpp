#include<iostream>
using namespace std;


class Node{
    public:
    int val;
    Node *next;

    Node(int data){
        val= data;
        next=NULL;
    }
};

void insertAtHead(Node* &head,int val){
    Node* new_node=new Node(val);
    new_node->next=head;
    head=new_node; 
}

void insertAtTail(Node* &head,int val){
    Node* temp=head;
    Node* new_node=new Node(val);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
}

void insertAtKthPosition(Node* head,int val){
    Node* temp=head;
    Node* new_node=new Node(val);
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    int i=1;
    if(k==1){
        insertAtHead(head,val);
        return;
    }
    else{
        while(i!=k-1){
            temp=temp->next;
            i++;
        }
        new_node->next=temp->next;
        temp->next=new_node;
    }
}

void updateAtKthPosition(Node* &head,int val){
    Node* temp=head;
    int i=1;
    cout<<"Enter the position where the value is to be updated: ";
    int k;cin>>k;
    while(i!=k){
        temp=temp->next;
        i++;
    }
    temp->val=val;
}

void display(Node * head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void deleteAtHead(Node* &head){
    Node* temp=head;
    head=temp->next;
    free(temp);
}

void deleteAtTail(Node* &head){
    Node* second_last=head;
    while(second_last->next->next!=NULL){
        second_last=second_last->next;
    }
    Node* temp=second_last->next;
    second_last->next=NULL;
    free(temp);
}

void deleteAtKthNode(Node* &head){
    Node* prev_node=head;
    cout<<"Enter the position of node to be deleted: ";
    int k; cin>>k;
    int i=1;
    if(k==1){
        deleteAtHead(head);
        return;
    }
    else{
        while(i!=k-1){
            prev_node=prev_node->next;
            i++;
        }
        Node* temp=prev_node->next;
        prev_node->next=prev_node->next->next;
        free(temp);
    }
}

int main(){
    Node* head=NULL;
    insertAtHead(head,2);
    display(head);
    insertAtHead(head,1);
    display(head);
    insertAtTail(head,5);
    display(head);
    insertAtTail(head,6);
    display(head);
    insertAtKthPosition(head,3);
    display(head);
    insertAtKthPosition(head,4);
    display(head);
    updateAtKthPosition(head,10);
    display(head);
    deleteAtHead(head);
    display(head);
    deleteAtTail(head);
    display(head);
    deleteAtKthNode(head);
    display(head);
    return 0;
}