#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v;
void add_edge(int src, int dest, bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}
void display(){
    for(int i=0;i<v;i++){
        cout<<i<<"->";
        for(auto ele: graph[i]){
            cout<<ele<<" ";
        }
        cout<<"\n";
    }
}

bool bfs(int src, vector<int>& par, unordered_set<int>& vis){
    queue<int> qu;
    qu.push(src);
    vis.insert(src);

    while(!qu.empty()){
        int node=qu.front();
        qu.pop();
        for(auto neighbor: graph[node]){
            if(vis.count(neighbor) && par[node]!=neighbor){
                return true;
            } else if(!vis.count(neighbor)){
                qu.push(neighbor);
                vis.insert(neighbor);
                par[neighbor]=node;
            }
        }
    }

    return false;
}

bool hasCycle(){
    vector<int> par(v, -1);
    unordered_set<int> vis;
    bool flag=false;
    for(int i=0;i<v;i++){
        if(!vis.count(i)){
            flag= bfs(i, par, vis);
            if(flag) return true;
        }
    }
    return false;
}

int main(){
    cin>>v;
    graph.resize(v, list<int>());
    int e;
    cin>>e;
    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s, d);
    }
    display();
    bool b=hasCycle();
    if(b) cout<<"Cycle Detected"<<endl;
    return 0;
}