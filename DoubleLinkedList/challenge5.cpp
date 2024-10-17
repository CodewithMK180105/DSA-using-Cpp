#include<iostream>
#include<vector>
#include<climits>
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

vector<int> targetSum(Node* head,Node* tail,int k){
    vector<int> ans(2,-1);
    while(head!=tail){
        if(head->val+tail->val==k){
            ans[0]=head->val;
            ans[1]=tail->val;
            return ans;
        }
        else if(head->val+tail->val > k){
            tail=tail->prev;
        }
        else if(head->val+tail->val < k){
            head=head->next;
        }
    }
    return ans;
}

int main(){
    DoublyLL dll;
    dll.insertAtTail(2);
    dll.insertAtTail(4);
    dll.insertAtTail(6);
    dll.insertAtTail(8);
    dll.insertAtTail(10);

    dll.display();

    vector<int> ans=targetSum(dll.head,dll.tail,11);
    cout<<ans[0]<<" "<<ans[1];
    
    return 0;
}
