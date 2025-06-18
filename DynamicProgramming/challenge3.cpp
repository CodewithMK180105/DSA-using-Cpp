// https://cses.fi/problemset/task/1634

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int recMemo(int n, int x, vector<int> &coins, vector<int> &dp){
    if(x==0) return 0;
    if(dp[x]!=-2) return dp[x];

    int res=INT_MAX;
    for(int i=0;i<n;i++){
        if(x>=coins[i]) res=min(res, recMemo(n, x-coins[i], coins, dp));
    }

    if(res==INT_MAX) return dp[x]=INT_MAX;
    else return dp[x]=1+res;
}

int Tabulation(int n, int x, vector<int> coins){
    
    
}
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> coins;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        coins.push_back(p);
    }
    vector<int> dp(x+1, -2);
    int ans=recMemo(n,x,coins,dp);
    if(ans==INT_MAX) cout<<-1;
    else cout<<ans;
    return 0;
}