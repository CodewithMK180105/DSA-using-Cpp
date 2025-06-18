// Given a number n perform any of the following operations on it some of the items.
// --> Reduce n to n-1
// --> if n is divisible by 2 then you can make it n/2
// --> if n is divisible by 3 then you can make it n/3
// Find out in how many min number of steps you can reduce n to 1.

#include<iostream>
#include<vector>
#include<climits>
#define inf INT_MAX
using namespace std;

// Top-down
int minSteps(int n, vector<int> &dp){
    if(n==1) return 0;
    if(dp[n]!=-1) return dp[n];

    int steps=minSteps(n-1, dp);
    if(n%2==0) steps=min(steps, minSteps(n/2, dp));
    if(n%3==0) steps=min(steps, minSteps(n/3, dp));
    return dp[n]=1+steps;
}

// Bottom-up
int minSteps2(int n){
    vector<int> dp(n+1, -1);
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;

    for(int i=4;i<n+1;i++){
        int steps=dp[i-1];
        steps=1+min(steps, min((i%2==0)? dp[i/2]: inf, (i%3==0)? dp[i/3]: inf));
        dp[i]=steps;
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    cout<<"Recursion + Memo "<<minSteps(n, dp)<<endl;
    cout<<"Tabulation "<<minSteps2(n)<<endl;
    return 0;
}