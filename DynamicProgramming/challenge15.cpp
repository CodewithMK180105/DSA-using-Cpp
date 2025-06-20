// https://www.spoj.com/problems/TOURIST/

#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
int dp[105][105][105];
char mat[105][105];
int f(int i, int j, int x, int y, int m, int n){
    if(i>=m || j>=n || x>=m || y>=n || mat[i][j]=='#' || mat[x][y]=='#') return INT_MIN;
    if(i==m-1 && j==n-1) return mat[i][j]=='*';
    if(dp[i][j][x]!=-1) return dp[i][j][x];
    
    int res=INT_MIN;
    res=max(res, f(i+1, j, x+1, y, m, n));
    res=max(res, f(i+1, j, x, y+1, m, n));
    res=max(res, f(i, j+1, x+1, y, m, n));
    res=max(res, f(i, j+1, x, y+1, m, n));


    if(mat[i][j]=='*') res++;
    if(mat[x][y]=='*') res++;

    if(i==x && j==y && mat[i][j]=='*') res--;


    return dp[i][j][x]=res;
}
int main(){
    int t; cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        memset(dp, -1, sizeof dp);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>mat[i][j];
            }
        }
        int result = f(0, 0, 0, 0, m, n);
        cout << (result == INT_MIN ? 0 : result) << '\n';
    }
    return 0;
}
