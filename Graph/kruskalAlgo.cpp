#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int findParent(vector<int>& parent, int x){
    if(parent[x]!=x) return parent[x]=findParent(parent, parent[x]);
    return x;
}

void Union(int a, int b, vector<int> &parent, vector<int> &rank){
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

ll kruskal(vector<Edge> &input, int n, int e){
    sort(input.begin(), input.end(), cmp);
    vector<int> rank(n+1, 1);
    vector<int> parent(n+1);

    for(int i=0;i<=n;i++){
        parent[i]=i;
    }

    int edgeCount=0; // n-1 a graph with n nodes can have maximun n-1 edges, if cycle not exists
    int i=0;
    ll ans=0;
    while(edgeCount<n-1 && i<input.size()){
        Edge curr=input[i];
        int srcPar=findParent(parent, curr.src);
        int destPar=findParent(parent, curr.dest);
        if(srcPar!=destPar){
            Union(srcPar, destPar, parent, rank);
            ans+=curr.wt;
            edgeCount++;
        }
        i++;
    }

    return ans;

}

int main(){
    int v,e;
    cin>>v>>e;
    vector<Edge> edges(e);
    for(int i=0;i<e;i++){
        cin>>edges[i].src>>edges[i].dest>>edges[i].wt;
    }
    cout<<kruskal(edges, v, e);
    return 0;
}