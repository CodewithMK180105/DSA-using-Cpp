// “Given an undirected weighted graph, along with a source (src) and destination (dest), find the shortest path between them in terms of the sum of edge costs.”

// Edge List:
// (0, 1, 1)  // src to node 1 with weight 1
// (0, 2, 3)  // src to node 2 with weight 3
// (1, 2, 1)  // node 1 to node 2 with weight 1
// (1, 3, 2)  // node 1 to dest with weight 2
// (2, 3, 1)  // node 2 to dest with weight 1

#include<bits/stdc++.h>
#define pp pair<int, int>
using namespace std;
vector<list<pp>> graph;
priority_queue<pp, vector<pp>, greater<pp>> pq;
unordered_map<int, int> mp;
vector<int> via;
unordered_set<int> vis;
void edge(int u, int v, int wt, bool bidir=true){
    graph[u].push_back({v, wt});
    if(bidir){
        graph[v].push_back({u, wt});
    }
}
void dijkstras(int src, int n){
    for(int i=0;i<n+1;i++){
        mp[i]=INT_MAX;
    }
    mp[src]=0;
    pq.push({0,0});
    while(!pq.empty()){
        auto curr=pq.top();
        if(vis.count(curr.second)){
            pq.pop();
            continue;
        }
        pq.pop();
        vis.insert(curr.second);
        for(auto neighbor: graph[curr.second]){
            if(!vis.count(neighbor.first) && mp[curr.second]+neighbor.second<mp[neighbor.first]){
                pq.push({neighbor.second, neighbor.first});
                mp[neighbor.first]=mp[curr.second]+neighbor.second;
                via[neighbor.first]=curr.second;
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    graph.resize(n+1, list<pp>());
    via.resize(n+1);
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        edge(u,v,wt);
    }

    int src;
    cin>>src;
    dijkstras(src, n);

    cout<<"node dist  via"<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<"     "<<mp[i]<<"     "<<via[i]<<endl;
    }

    return 0;
}

// 0 1 7
// 0 2 2
// 2 3 1
// 2 4 2
// 1 3 2
// 4 6 3
// 4 5 5
// 5 6 1