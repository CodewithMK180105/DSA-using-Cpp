#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int>> graph;
unordered_set<int> visited;
vector<vector<int>> result;
int v;
void add_edge(int src, int dest, bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}
void dfs(int curr, int end, vector<int> &path){
    if(curr==end){
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr);
    path.push_back(curr);
    for(auto neighbor: graph[curr]){
        if(!visited.count(neighbor)){
            dfs(neighbor, end, path);
        }
    }
    path.pop_back();
    visited.erase(curr);
    return;
}
void allPath(int src, int des){
    vector<int> v;
    dfs(src, des, v);
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
    
    int x,y; cin>>x>>y;
    allPath(x, y);
    for(auto vec: result){
        for(auto ele: vec){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}