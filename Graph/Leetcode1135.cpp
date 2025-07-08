// 1135. Connecting Cities With Minimum Cost
// Medium

// There are n cities labeled from 1 to n. You are given the integer n and an array connections where connections[i] = [xi, yi, costi] indicates that the cost of connecting city xi and city yi (bidirectional connection) is costi.

// Return the minimum cost to connect all the n cities such that there is exactly one simple path between any two cities. If it is impossible to connect all the cities, return -1.

// Example 1:
// Input: n = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
// Output: 6
// Explanation: Choosing any 2 edges will connect all cities so we choose the minimum 2.

// Example 2:
// Input: n = 4, connections = [[1,2,3],[3,4,4]]
// Output: -1
// Explanation: There is no way to connect all cities even though all the existing connections are used.

// Constraints:
// 1 <= n <= 10000
// 1 <= connections.length <= 10000
// connections[i].length == 3
// 1 <= xi, yi <= n
// xi != yi
// 0 <= costi <= 10^5

#include<bits/stdc++.h>
using namespace std;
int findParent(vector<int>& parent, int x){
    if(parent[x]!=x) return parent[x]=findParent(parent, parent[x]);
    return x;
}
void Union(int a, int b, vector<int> &parent, vector<int>& rank){
    int pa=findParent(parent, a);
    int pb=findParent(parent, b);

    if(pa==pb) return;

    if(rank[pa]>=rank[pb]){
        parent[pb]=pa;
        rank[pa]++;
    } else{
        parent[pa]=pb;
        rank[pb]++;
    }
}

struct Edge{
    int src;
    int dest;
    int wt;
};

bool cmp(Edge e1, Edge e2){
    return e1.wt<e2.wt;
}
int kruskal(vector<Edge>& edges, int n, vector<int>& parent, vector<int>& rank){
    int edgeCount=0, i=0, ans=0;
    sort(edges.begin(), edges.end(), cmp);
    while(edgeCount<=n-1 && i<edges.size()){
        Edge curr=edges[i];
        int srcPar=findParent(parent, curr.src);
        int destPar=findParent(parent, curr.dest);
        if(srcPar!=destPar){
            Union(srcPar, destPar, parent, rank);
            edgeCount++;
            ans+=curr.wt;
        }
        i++;
    }

    return edgeCount==n-1? ans: -1;
}
int main(){
    int v; cin>>v;
    vector<int> parent(v+1);
    vector<int> rank(v+1);
    vector<Edge> edges={{1,2,3}, {3,4,4}};

    for(int i=0;i<v+1;i++){
        parent[i]=i;
    }

    cout<<kruskal(edges, v, parent, rank);
    return 0;
}