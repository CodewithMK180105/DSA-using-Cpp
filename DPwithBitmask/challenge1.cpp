// https://atcoder.jp/contests/dp/tasks/dp_o


#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
#define mod 1000000007

int dp[22][1<<22];
int f(int i, int mask, int n, vector<vector<int>> &grid){
    if(i==n+1){
        if(mask==0) return dp[i][mask]=1;
        return dp[i][mask]=0;
    }
    if(dp[i][mask]!=-1) return dp[i][mask];

    int ans=0;
    for(int w=1;w<=n;w++){
        bool available=(((1<<(w-1))&mask)==0)? 0:1;
        if(grid[i][w] && available){
            ans=((ans%mod)+(f(i+1, mask^(1<<(w-1)), n, grid))%mod)%mod;
        }
    }
    return dp[i][mask]=ans;
}
int main(){
    int n; cin>>n;
    vector<vector<int>> grid(n+1, vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>grid[i][j];
        }
    }

    memset(dp, -1, sizeof dp);

    cout<<f(1, (1<<n)-1, n, grid);  
    return 0;
}