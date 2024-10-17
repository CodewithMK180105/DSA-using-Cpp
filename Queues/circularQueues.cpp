#include<iostream>
using namespace std;
class CircularQueue{
    public:
    int size;
    int front, rear;
    int *queue;

    CircularQueue(int size){
        this->size=size;
        this->front=this->rear=-1;
        queue=new int[size];
    }

    void enqueue(int val){
        if(front==-1){
            front=rear=0;
            queue[rear]=val;
        }
        else if((rear+1)%size==front){
            cout<<"Queue is full";
            return;
        }
        else{
            rear=(rear+1)%size;
            queue[rear]=val;
        }
    }

    void dequeue(){
        if(front==-1) cout<<"Queue is empty";
        else if(front==rear){
            front=rear=-1;
        }
        else{
            front=(front+1)%size;
        }
    }

    void display(){
        if(front==-1) cout<<"Queue is empty";
        else{
            int i=front;
            do{
                cout<<queue[i]<<" ";
                i=(i+1)%size;
            }while(i != (rear + 1) % size);
            cout<<endl;
        }
    }
};
int main(){
    CircularQueue cq(5);  // Create a circular queue with a maximum size of 5

    // Enqueue elements
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    // Try to enqueue another element (queue is full)
    cq.enqueue(60);

    // Display the queue
    cq.display();

    // Dequeue elements
    cq.dequeue();
    cq.dequeue();

    // Display the queue after dequeue
    cq.display();

    // Enqueue more elements
    cq.enqueue(60);
    cq.enqueue(70);

    // Display the queue again
    cq.display();
    return 0;
}