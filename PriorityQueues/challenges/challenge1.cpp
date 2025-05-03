// Minimum cost to connect all the ropes

// Given n ropes of different lengths, we need to connect these ropes into one rope. The cost of connecting two ropes is equal to the sum of their lengths. The task is to connect the ropes with minimum cost.
// We can connect the two smallest ropes at a time. The cost of connecting two ropes is equal to the sum of their lengths. The task is to connect the ropes with minimum cost.

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(){
    vector<int> v={2,7,4,1,8};
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<v.size();i++){
        pq.push(v[i]);
    }

    int cost=0;
    while(pq.size()>1){
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();

        cost+=a+b;
        pq.push(a+b);
    }

    cout<<cost;
    return 0;
}