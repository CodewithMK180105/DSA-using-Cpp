#include <iostream>
#include <cstdlib>
#include <unordered_set>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val=val;
        this->next=NULL;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout<<head->val<<" ";
        head=head->next;
    }
}

int main() {
    int n;
    cout<<"Enter a number: ";
    cin >> n;

    unordered_set<int> s;
    while (s.size()<n) {
        int num=rand()%(n*10);
        s.insert(num);
    }

    ListNode* head=NULL;
    ListNode* temp=NULL;
    for (int val:s) {
        ListNode* newNode=new ListNode(val);
        if (!head) {
            head=newNode;
            temp=head;
        } else {
            temp->next=newNode;
            temp=temp->next;
        }
    }
    cout <<"Linked list with unique random elements: "<<endl;
    printList(head);
    return 0;
}
