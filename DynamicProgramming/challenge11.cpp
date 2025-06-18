// https://atcoder.jp/contests/dp/tasks/dp_l
// https://chatgpt.com/c/68501e88-c76c-8000-a233-eccba159a701

#include<iostream>
#include<vector>
using namespace std;
long long xminusY(vector<long long> &v, int i, int j, vector<vector<long long>> &dp){
    if(i==j) return v[i];
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=max(v[i]-xminusY(v,i+1,j,dp), v[j]-xminusY(v,i,j-1,dp));
}

long long tabulation(int n, vector<long long> &v){
    vector<vector<long long>> dp(n, vector<long long>(n));
    for(int i=0;i<n;i++){
        dp[i][i]=v[i];
    }

    for(int len=2;len<=n;len++){
        for(int i=0;i+len<=n;i++){
            int j=i+len-1;
            dp[i][j]=max(v[i]-dp[i+1][j], v[j]-dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}
int main(){
    int n; cin>>n;
    vector<long long> v;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        v.push_back(x);
    }
    // vector<vector<long long>> dp(n, vector<long long>(n, -1));
    // cout<<xminusY(v, 0, n-1, dp);
    cout<<tabulation(n, v);
    return 0;
}