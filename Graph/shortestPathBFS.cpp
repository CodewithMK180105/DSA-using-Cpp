#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<climits>
#include<unordered_set>
using namespace std;
vector<list<int>> graph;
unordered_set<int> visited;
// vector<vector<int>> result;
int v;
void add_edge(int src, int dest, bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

void bfs(int src, vector<int> &dist){
    queue<int> qu;

    dist.resize(v, INT_MAX);
    dist[src]=0;
    visited.insert(src);
    qu.push(src);

    while(!qu.empty()){
        int curr=qu.front();
        cout<<curr<<" ";
        qu.pop();
        for(auto neighbor: graph[curr]){
            if(!visited.count(neighbor)){
                visited.insert(neighbor);
                qu.push(neighbor);
                dist[neighbor]=dist[curr]+1;
            }
        }
    }

    cout<<endl;
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
    
    int x; cin>>x;
    
    vector<int> dist;
    bfs(x, dist);
    for(int i=0; i<v;i++){
        cout<<dist[i]<<" ";
    }

    return 0;
}