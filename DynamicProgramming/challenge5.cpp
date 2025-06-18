// https://www.spoj.com/problems/MCOINS/

#include<iostream>
#include<vector>
using namespace std;
int mcoins(int n, int k, int l, vector<int> &dp){
    if(n==0) return 0;

    if(dp[n]!=-1) return dp[n];

    if(n>=1 && mcoins(n-1,k,l,dp)==0) return dp[n]=1;
    if(n>=k && mcoins(n-k,k,l,dp)==0) return dp[n]=1;
    if(n>=l && mcoins(n-l,k,l,dp)==0) return dp[n]=1;

    return dp[n]=0;
}
int mcoinstabulation(int n, int k, int l){
    vector<int> dp(n+1, -1);

    for(int i=0;i<n+1;i++){
        if(i>=1 && dp[i-1]==0) dp[i]=1;
        else if(i>=k && dp[i-k]==0) dp[i]=1;
        else if(i>=l && dp[i-l]==0) dp[i]=1;
        else dp[i]=0;
    }

    return dp[n];

}
int main(){
    int t,k,l;
    cin>>k>>l>>t;
    // for(int i=0;i<t;i++){
    //     int n;
    //     cin>>n;
    //     vector<int> dp(n+1, -1);
    //     if(mcoins(n,k,l,dp)) cout<<"A";
    //     else cout<<"B";
    // }

    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        if(mcoinstabulation(n,k,l)) cout<<"A";
        else cout<<"B";
    }
    return 0;
}