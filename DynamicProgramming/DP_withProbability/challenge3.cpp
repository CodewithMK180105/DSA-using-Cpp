// https://www.spoj.com/problems/MPILOT/

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int dp[10005][5050];
int minCost2(vector<int> cap, vector<int> ass, int n, int i, int x){
    if(i==n) return 0;  
    if(dp[i][x]!=-1) return dp[i][x];

    if(x==0) return dp[i][x]=minCost2(cap, ass, n, i+1, x+1)+ass[i];
    else if(x==n-i) return dp[i][x]=minCost2(cap, ass, n, i+1, x-1)+cap[i];
    else return dp[i][x]=min(minCost2(cap, ass, n, i+1, x+1)+ass[i], minCost2(cap, ass, n, i+1, x-1)+cap[i]);
}
int minCost(vector<int> cap, vector<int> ass, int n, int i, int ca, int cc){
    if(i==n) return 0;  

    if(ca==cc) return minCost(cap, ass, n, i+1, ca+1, cc)+ass[i];
    else if(ca==n/2) return minCost(cap, ass, n, i+1, ca, cc+1)+cap[i];
    else return min(minCost(cap, ass, n, i+1, ca+1, cc)+ass[i], minCost(cap, ass, n, i+1, ca, cc+1)+cap[i]);
}
int main(){
    int n;
    cin>>n;
    vector<int> ass;
    vector<int> cap;
    memset(dp, -1, sizeof dp);
    for(int i=0;i<n;i++){
        int c,a;
        cin>>c>>a;
        cap.push_back(c);
        ass.push_back(a);
    }
    cout<<minCost2(cap, ass, n, 0, 00);
    return 0;
}