#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
int v;
void add_edge(int a, int b, bool bidir= true){
    graph[a].push_back(b);
    if(bidir){
        graph[b].push_back(a);
    }
}
void topoBFS(){
    // Kahn's Algorithm
    vector<int> indegree(v,0);
    for(int i=0;i<v;i++){
        for(auto neighbor: graph[i]){
            indegree[neighbor]++;
        }
    }

    queue<int> qu;
    unordered_set<int> vis;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            qu.push(i);
            vis.insert(i);
        }
    }

    while(!qu.empty()){
        int node=qu.front();
        cout<<node<<" ";
        qu.pop();
        for(auto neighbor: graph[node]){
            if(vis.count(neighbor)) continue;
            indegree[neighbor]--;
            if(indegree[neighbor]==0){
                qu.push(neighbor);
                vis.insert(neighbor);
            }
        }
    }
}
int main(){
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v, list<int>());
    while(e--){
        int x,y;
        cin>>x>>y;
        add_edge(x,y, false);
    }
    
    topoBFS();
    return 0;
}