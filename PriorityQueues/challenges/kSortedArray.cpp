#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    vector<int> v={6, 5, 3, 2, 8, 10, 9};
    int n=v.size();
    int k=3;
    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i=0;i<=k;i++){
        pq.push(v[i]);
    }

    for(int i=0;i<n-k-1;i++){
        v[i]=pq.top();
        pq.pop();
        pq.push(v[i+k+1]);
    }

    for(int i=n-k-1;i<n;i++){
        v[i]=pq.top();
        pq.pop();
    }

    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}