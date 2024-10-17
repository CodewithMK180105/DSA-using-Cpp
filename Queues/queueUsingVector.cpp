#include<iostream>
#include<vector>
using namespace std;
class Queue{
    public:
        int front;
        int back;
        vector<int> v;

        Queue(){
            front=-1;
            back=-1;
        }

        void enque(int data){
            v.push_back(data);
            if(front==-1) front++;
            back++;
        }

        void dequeue(){
            if(front==-1) return;
            if(front==back){
                front=back=-1;
                v.clear();
            }
            else front++;
        }

        int getFront(){
            if(front==-1) return -1;
            else return v[front];
        }

        bool isEmpty(){
            return front==-1;
        }
};
int main(){
    Queue qu;
    qu.enque(10);
    qu.enque(100);
    qu.enque(30);
    qu.dequeue();
    qu.enque(40);
    qu.dequeue();
    qu.dequeue();
    qu.dequeue();
    qu.enque(500);
    while(not qu.isEmpty()){
        cout<<qu.getFront()<<" ";
        qu.dequeue();
    }
    return 0;
}