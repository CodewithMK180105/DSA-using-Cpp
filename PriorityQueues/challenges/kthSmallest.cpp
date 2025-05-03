#include<iostream>
#include<queue>
using namespace std;
int main(){
    vector<int> v={10, 20,-4, 6, 18, 2, 105, 118};
    priority_queue<int> pq;
    int k=5;

    for(int i=0;i<v.size();i++){
        pq.push(v[i]);
        if(pq.size()>k){
            pq.pop();
        }
    }

    cout<<pq.top();

    return 0;
}