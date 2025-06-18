// https://cses.fi/problemset/task/1637

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> extractDigits(int n){
    vector<int> v;
    while(n>0){
        if(n%10!=0) v.push_back(n%10);
        n/=10;
    }
    return v;
}
int count(int n, vector<int> &dp){
    if(n==0) return 0;
    if(n<=9) return 1;

    if(dp[n]!=-1) return dp[n];

    vector<int> v=extractDigits(n);
    int result=INT_MAX;
    for(int i=0;i<v.size();i++){
        result=min(result, count(n-v[i], dp));
    }

    return dp[n]=1+result;
}

int countWithTabulation(int n){
    if(n==0) return 0;
    if(n<=9) return 1;

    vector<int> dp(n+1, 1);
    dp[0]=0;

    for(int i=10;i<n+1;i++){
        vector<int> v=extractDigits(i);
        int mini=INT_MAX;
        for(int j=0;j<v.size();j++){
            if(v[j]!=0) mini=min(mini, dp[i-v[j]]);
        }
        dp[i]=1+mini;
        // cout<<i<<"->"<<dp[i]<<" ";
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    cout<<countWithTabulation(n);
    return 0;
}