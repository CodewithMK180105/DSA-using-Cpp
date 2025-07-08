#include<iostream>
#include<vector>
using namespace std;
int findParent(int x, vector<int>& par){
    if(par[x]!=x) return par[x]=findParent(par[x], par);
    return par[x];
}

bool Union(int a, int b, vector<int>& par, vector<int>& rank){
    int pa=findParent(a, par);
    int pb=findParent(b, par);

    if(pa==pb) return true;

    if(rank[pa]>=rank[pb]){
        rank[pa]++;
        par[pb]=pa;
    } else{
        rank[pb]++;
        par[pa]=pb;
    }

    return false;
}
int main(){
    int n,m;
    cin>>n>>m; // n=number of elements, m=number of queries

    vector<int> par(n+1);
    vector<int> rankVal(n+1, 0);
    for(int i=0;i<n+1;i++){
        par[i]=i;
    }

    while(m--){
        int x,y;
        cin>>x>>y;
        bool flag=Union(x, y, par, rankVal);
        if(flag){
            cout<<"Cycle Detected"<<endl;
            break;
        }
    }

    return 0;
}