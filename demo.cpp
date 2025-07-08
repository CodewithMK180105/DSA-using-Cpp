#include<bits/stdc++.h>
#define pp pair<int, int>
using namespace std;
vector<list<pp>> graph; // node, wt
unordered_set<int> vis; // node
priority_queue<pp, vector<pp>, greater<pp>> pq; // wt, node
unordered_map<int, int> mp; // node, dist
void edge(int u, int v, int wt, bool bidir=true){
    graph[u].push_back({v, wt});
    if(bidir){
        graph[v].push_back({u, wt});
    }
}
int prims(int src, int n){
    vector<int> par(n+1,0);
    for(int i=0;i<n+1;i++){
        mp[i]=INT_MAX;
    }
    par[src]=0;
    int res=0;
    pq.push({0, src});
    int edgeCount=0;
    while(edgeCount<n && !pq.empty()){
        pp curr=pq.top();
        int weight=curr.first;
        int node=curr.second;
        if(vis.count(node)){
            pq.pop();
            continue;
        }
        vis.insert(node);
        res+=weight;
        edgeCount++;
        pq.pop();
        for(pp neighbor: graph[node]){
            if(!vis.count(neighbor.first) && mp[neighbor.first]>neighbor.second){
                pq.push({neighbor.second, neighbor.first});
                par[neighbor.first]=node;
                mp[neighbor.first]=neighbor.second;
            }
        }
    }
    return res;
}
int main(){
    int n, m;
    cin>>n>>m;
    graph.resize(n+1, list<pp>());
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        edge(u,v,wt);
    }
    int src; cin>>src;
    cout<<prims(src, n);
    return 0;
}




// 9 12
// 0 1 4
// 0 4 1
// 0 7 3
// 1 2 1
// 2 3 4
// 2 4 1
// 3 6 2
// 4 5 4
// 4 8 2
// 5 6 3
// 5 8 3
// 8 7 1