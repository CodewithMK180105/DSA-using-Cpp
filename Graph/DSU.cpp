#include<iostream>
#include<vector>
using namespace std;
int find(int x, vector<int>& par){
    // log* (n)
    if(par[x]!=x) par[x]=find(par[x], par);
    return par[x];
}
void union_op(int a, int b, vector<int>& par, vector<int>& rankVal){

    int pa=find(a, par); // log* (n)
    int pb=find(b, par); // log* (n)

    if(rankVal[pa]>=rankVal[pb]){
        par[pb]=pa;
        rankVal[pa]++;      
    } else{
        par[pa]=pb;
        rankVal[pb]++;
    }
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
        string str;
        cin>>str;
        if(str=="union"){
            int x,y;
            cin>>x>>y;
            union_op(x, y, par, rankVal);
        } else{
            int x;
            cin>>x;
            cout<<find(x, par);
        }
    }

    return 0;
}