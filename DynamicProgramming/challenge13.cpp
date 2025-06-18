// K-ordered Longest Common Subsequence

#include<iostream>
#include<vector>
using namespace std;
int ftd(vector<int> &text1, vector<int> &text2, int i, int j, vector<vector<vector<int>>> &dp, int k){
    if(i<0 || j<0) return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    if(text1[i]==text2[j]) return dp[i][j][k]=1+ftd(text1, text2, i-1, j-1, dp, k);
    else if(k>0) return dp[i][j][k]=max(1+ftd(text1, text2, i-1, j-1, dp, k-1), max(ftd(text1, text2, i-1, j, dp, k),ftd(text1, text2, i, j-1, dp, k)));
    else return dp[i][j][k]=max(ftd(text1, text2, i-1, j, dp, k),ftd(text1, text2, i, j-1, dp, k));
}
int fbu(vector<int> &text1, vector<int> &text2, int n, int m, int k){
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1,vector<int>(k+1, 0)));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int l=0;l<=k;l++){
                if(text1[i-1]==text2[j-1]) dp[i][j][l]=1+dp[i-1][j-1][l];
                else if(l>0) dp[i][j][l]=max(1+dp[i-1][j-1][l-1], max(dp[i-1][j][l],dp[i][j-1][l]));
                else dp[i][j][l]=max(dp[i-1][j][l],dp[i][j-1][l]);
            }
        }
    }
    return dp[n][m][k];
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> v1,v2;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m,vector<int>(k+1, -1)));
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v1.push_back(x);
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        v2.push_back(x);
    }
    // cout<<ftd(v1, v2, n-1, m-1, dp, k)<<endl; 
    cout<<fbu(v1, v2, n, m, k)<<endl; 
    return 0;
}