// Longest Common Subsequence

#include<iostream>
#include<vector>
using namespace std;
int ftd(string &text1, string &text2, int i, int j, vector<vector<int>> &dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(text1[i]==text2[j]) return dp[i][j]=1+ftd(text1, text2, i-1, j-1, dp);
    else return dp[i][j]=max(ftd(text1, text2, i-1, j, dp),ftd(text1, text2, i, j-1, dp));
}
int main(){
    string text1="oxcpqrsvwf"; 
    int m=text1.size();
    string text2="shmtulqrypy";
    int n=text2.size();
    vector<vector<int>> dp(m, vector<int>(n,0));
    cout<<ftd(text1, text2, m-1, n-1, dp); 
    return 0;
}