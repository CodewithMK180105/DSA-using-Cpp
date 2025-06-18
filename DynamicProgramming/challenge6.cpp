// https://atcoder.jp/contests/dp/tasks/dp_c

#include<iostream>
#include<vector>
using namespace std;
int recMemo(int n, vector<vector<int>> &points, int idx, int last, vector<vector<int>> &dp){
    if(n==idx) return 0;

    if(dp[idx][last]!=-1) return dp[idx][last];

    int ans=0;
    for(int task=0;task<3;task++){
        if(last!=task){
            int score=points[idx][task]+recMemo(n, points, idx+1, task, dp);
            ans=max(ans, score);
        }
    }

    return dp[idx][last]=ans;
}

int tabulation(int n, vector<vector<int>> &points){
    if(n==1) return max(points[0][0], max(points[0][1], points[0][2]));

    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            if(j==0) points[i][j]+=max(points[i-1][1],points[i-1][2]);
            if(j==1) points[i][j]+=max(points[i-1][0],points[i-1][2]);
            if(j==2) points[i][j]+=max(points[i-1][0],points[i-1][1]);
        }
    }

    return max(points[n-1][0], max(points[n-1][1], points[n-1][2]));
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> points(n, vector<int>(3));

    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        points[i][0]=a;
        points[i][1]=b;
        points[i][2]=c;
    }
    
    // vector<vector<int>> dp(n, vector<int>(4, -1));
    // cout<<recMemo(n, points, 0, 3, dp);

    cout<<tabulation(n, points);
    return 0;
}   