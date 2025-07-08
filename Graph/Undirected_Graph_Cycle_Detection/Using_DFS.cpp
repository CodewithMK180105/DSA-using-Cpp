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

bool dfs(int src, int par, unordered_set<int> &vis){
    vis.insert(src);
    for(auto neighbor: graph[src]){
        if(neighbor!=par && vis.count(neighbor)){
            return true;
        } else if(!vis.count(neighbor)) return dfs(neighbor, src, vis);
    }
    return false;
}

bool hasCycle(){
    unordered_set<int> vis;
    bool result=false;
    for(int i=0;i<v;i++){  // For disconnected graph all nodes to be visited
        if(!vis.count(i)){
            result=dfs(i, -1, vis);
            if(result==true) return true;
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