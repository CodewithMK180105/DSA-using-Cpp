#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> v={10,1,2,20,5,8};

    int n=v.size();
    for(int i=0;i<n;i++){
        pq.push(v[i]);
    }

    int i=0;
    while(!pq.empty()){
        v[i]=pq.top();
        i++;
        pq.pop();
    }

    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}