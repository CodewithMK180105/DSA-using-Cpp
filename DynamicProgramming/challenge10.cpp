// No. of subtrees

#include<iostream>
#include<vector>
using namespace std;
int helper(int n, vector<int> &dp){
    if(n==0 || n==1) return 1;
    if(n==2) return 2;
    if(dp[n]!=-1) return dp[n];
    int result=0;
    for(int i=1;i<=n;i++){
        result+=helper(i-1, dp)*helper(n-i, dp);
    }
    return dp[n]=result;
}
int numTrees(int n) {
    vector<int> dp(n+1,-1);
    return helper(n, dp);
}
int numTreesTabulation(int n){
        if(n==0 || n==1) return 1;
        if(n==2) return 2;

        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;

        for(int i=3;i<=n;i++){
            for(int k=1;k<=i;k++){
                dp[i]+=dp[k-1]*dp[i-k];
            }
        }
        return dp[n];
    }
int main(){
    int n; cin>>n;
    cout<<numTrees(n);
    return 0;
}