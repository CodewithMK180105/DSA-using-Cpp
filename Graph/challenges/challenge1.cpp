// Problem Description:

// Implement disjoint sets union data structure. You have to perform queries of two types:

// union u v — unite two sets that contain u and v, respectively;

// get u — find the set to which u belongs to, find the minimal and the maximal element of the set, and the total number of elements in it.

// Input:
// The first line of the input contains two integers n and m (1 ≤ n, m ≤ 3 * 10^5) — the number of elements and the number of queries.
// Next m lines contain queries, one per line. For a query union, the line looks like union u v (1 ≤ u, v ≤ n).
// For a query get, the line looks like get u (1 ≤ u ≤ n).

// Output:
// For each operation get you should output the result on a separate line in the respected order.
// Each result should consist of three integers: the minimal element, the maximal element and the number of elements in the set.

// Input:
// 5 11
// union 1 2
// get 3
// get 2
// union 2 3
// get 2
// union 1 3
// get 5
// union 4 5
// get 5
// union 4 1
// get 5

// Output:
// 3 3 1
// 1 2 2
// 1 3 3
// 5 5 1
// 4 5 2
// 1 5 5


#include<iostream>
#include<vector>
using namespace std;
int find(int x, vector<int>& par){
    if(par[x]!=x) return par[x]=find(par[x], par);
    return x;
}
void Union(int a, int b, vector<int>& par, vector<int>& sz, vector<int>& minimal, vector<int>& maximal){
    int pa=find(a, par);
    int pb=find(b, par);

    if(pa==pb) return;

    if(sz[pa]>=sz[pb]){
        par[pb]=pa;
        sz[pa]+=sz[pb];
        minimal[pa]=min(minimal[pa], minimal[pb]);
        maximal[pa]=max(maximal[pa], maximal[pb]);
    } else{
        par[pa]=pb;
        sz[pb]+=sz[pa];
        minimal[pb]=min(minimal[pa], minimal[pb]);
        maximal[pb]=max(maximal[pa], maximal[pb]);
    }
}
int main(){
    int n, m;
    cin>>n>>m;

    vector<int> par(n+1);
    vector<int> sz(n+1, 1);
    vector<int> minimal(n+1);
    vector<int> maximal(n+1);

    for(int i=0;i<n+1;i++){
        par[i]=i;
        minimal[i]=i;
        maximal[i]=i;
    }
    
    for(int i=0;i<m;i++){
        string str;
        cin>>str;
        if(str=="union"){
            int u, v;
            cin>>u>>v;
            Union(u,v,par,sz,minimal,maximal);
        } else {
            int ele; cin>>ele;
            int parent=find(ele, par);
            cout<<minimal[parent]<<" "<<maximal[parent]<<" "<<sz[parent]<<endl;
        }
    }
}
