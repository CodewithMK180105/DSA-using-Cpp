#include<bits/stdc++.h>
#define ll long long int
#define pp pair<int,int>
using namespace std;
vector<list<pp>> gr; // vertex, wt
void edge(int u, int v, int wt, bool bidir=true){
    gr[u].push_back({v, wt});
    if(bidir){
        gr[v].push_back({u, wt});
    }
}

ll prims(int src, int n){
    priority_queue<pp, vector<pp>, greater<pp>> pq; // wt, dest
    unordered_set<int> vis;
    vector<int> par(n+1);
    unordered_map<int, int> mp; //node, disc wt
    for(int i=1;i<n+1;i++){
        mp[i]=INT_MAX;
    }
    pq.push({0, src});
    mp[src]=0;
    int totalEdges=0; // 0 to n-1 edges
    int result=0;
    while(totalEdges<n && !pq.empty()){ 
        pp curr=pq.top();
        if(vis.count(curr.second)){
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        totalEdges++;
        result+=curr.first;
        pq.pop();
        for(auto neighbor: gr[curr.second]){
            if(!vis.count(neighbor.first) && mp[neighbor.first]>neighbor.second){
                pq.push({neighbor.second, neighbor.first});
                par[neighbor.first]=curr.second;
                mp[neighbor.first]=neighbor.second;
            }
        }
    }
    return result;
}
int main(){
    int n,m;
    cin>>n>>m;
    gr.resize(n+1, list<pp>());
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        edge(u,v,wt);
    }
    int src; cin>>src;
    cout<<prims(src, n);
    return 0;
}