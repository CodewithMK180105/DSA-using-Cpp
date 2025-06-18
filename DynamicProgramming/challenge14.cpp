// https://www.spoj.com/problems/GNYR09F/

#include <bits/stdc++.h>
using namespace std;
int dp[105][105][2];
int f(int n, int k, int last){
    if(k<0) return 0;
    if(n==0) return k==0?1:0;

    if(dp[n][k][last]!=-1) return dp[n][k][last];
    
    int a=0,b=0,c=0,d=0;
    if(last==0) a=f(n-1,k, 0);
    if(last==0) b=f(n-1,k, 1);
    if(last==1) c=f(n-1,k, 0);
    if(last==1) d=f(n-1,k-1, 1);

    return dp[n][k][last]=a+b+c+d;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int num,n,k;
        cin>>num>>n>>k;
        memset(dp, -1, sizeof dp);
        cout<<num<<" "<<f(n-1, k, 0)+f(n-1, k, 1)<<endl;
    }
    return 0;
}