// Travelling Salesman Problem

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int tsp(vector<list<pair<int, int>>>& graph, int &n, int curr, int mask){
    if (((1 << n) - 1) == mask) {
        for (auto neighbor : graph[curr]) {
            if (neighbor.first == 0) {
                return neighbor.second; // Cost to return to start
            }
        }
        return INT_MAX; // No path back to start
    }
    if(dp[curr][mask]!=-1) return dp[curr][mask];

    int res=INT_MAX;
    
    for(auto neighbor: graph[curr]){
        int des=neighbor.first;
        int w=neighbor.second;

        if(((mask>>des)&1)==0){
            res=min(res,w+tsp(graph, n, des,((1<<des)|mask)));
        }
    }

    return dp[curr][mask]=res;
}
int main(){
    int n,e; // number of the nodes, edges
    cin>>n>>e;
    vector<list<pair<int, int>>> graph(n);
    dp.clear();
    dp.resize(n, vector<int>((1<<n), -1));
    for(int i=0;i<e;i++){
        int src, dest, wt; cin>>src>>dest>>wt;
        graph[src].push_back({dest, wt});
        graph[dest].push_back({src, wt});
    }

    cout<<tsp(graph, n, 0, 1);
    return 0;
}