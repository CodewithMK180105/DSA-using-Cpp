// https://www.spoj.com/problems/MIXTURES/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int g(vector<int> &colors, int i, int j){
    int result=0;
    for(int m=i;m<=j;m++){
        result=(result+colors[m])%100;
    }
    return result;
}
int f(vector<int> &colors, int i, int j, vector<vector<int>> &dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int result=INT_MAX;
    for(int k=i;k<=j-1;k++){
        result=min(result, f(colors, i, k, dp)+f(colors, k+1, j, dp)+g(colors, i, k)*g(colors, k+1, j));
    }
    return dp[i][j]=result;
}
int main(){
    int n;
    while(cin>>n){
        vector<int> colors;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            colors.push_back(x);
        }
        vector<vector<int>> dp(n, vector<int> (n, -1));
        cout<<f(colors, 0, colors.size()-1, dp)<<endl;
        colors.clear();
    }
    return 0;
}