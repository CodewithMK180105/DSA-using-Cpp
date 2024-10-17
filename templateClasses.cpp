#include<iostream>
using namespace std;

template <typename T>
class Node{
    public:
        T val;
        Node* next;
        
        Node(T data){
            val=data;
            next=NULL;
        }
};

int main(){
    
    Node<int>* n1=new Node<int>(1);
    cout<<n1->val<<endl;
    
    Node<char>* n2=new Node<char>('a');
    cout<<n2->val<<endl;
    
    return 0;
}