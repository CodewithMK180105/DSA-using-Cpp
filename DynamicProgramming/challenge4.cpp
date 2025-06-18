// https://cses.fi/problemset/task/1633

#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;
const int MOD = 1e9 + 7;
int recMemo(int n, vector<int> &dp){
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    int res=0;
    for(int i=1;i<=n && i<=6;i++){
        res=(res+recMemo(n-i, dp))%MOD;
    }

    return dp[n]=res;
}

int tabulation(int n){
    vector<int> dp(n+1, 0);
    dp[0]=1;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<=6;j++){
            if(i-j>=0){
                dp[i]=(dp[i]+dp[i-j])%MOD;
            }
        }
    }
    
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    cout<<tabulation(n);
    return 0;
}