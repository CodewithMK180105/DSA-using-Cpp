#include<iostream>
#include<queue>
using namespace std;
int main(){

    // Max Heap

    // priority_queue<int> pq; // In cpp, it is max heap by default
    // pq.push(10);
    // pq.push(25);
    // pq.push(-6);
    // pq.push(81);
    // cout<<pq.top()<<endl;
    // pq.pop();
    // cout<<pq.top()<<endl;
    // return 0;

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> pq; // In cpp, it is max heap by default
    pq.push(10);
    pq.push(25);
    pq.push(-6);
    pq.push(81);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    return 0;
}