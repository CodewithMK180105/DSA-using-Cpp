#include<iostream>
#include<vector>
using namespace std;
int f(vector<vector<int>>& grid, int i, int j, int m, int n){
    if(grid[i][j]==1) return 0;
    if(i==m-1 && j==n-1) return 1;

    int u=0, d=0, l=0, r=0;
    grid[i][j]=1;
    if(i>0) u=f(grid, i-1, j, m, n);
    if(i<m-1) d=f(grid, i+1, j, m, n);
    if(j>0) l=f(grid, i, j-1, m, n);
    if(j<n-1) r=f(grid, i, j+1, m, n);
    grid[i][j]=0;
    return u+d+l+r;
}

vector<string> res;
void fprint(vector<vector<int>>& grid, int i, int j, int m, int n, string ans){
    if(grid[i][j]==1) return;
    if(i==m-1 && j==n-1) {
        res.push_back(ans);
        return;
    }

    grid[i][j]=1;
    if(i>0) fprint(grid, i-1, j, m, n, ans+"U");
    if(i<m-1) fprint(grid, i+1, j, m, n, ans+"D");
    if(j>0) fprint(grid, i, j-1, m, n, ans+"L");
    if(j<n-1) fprint(grid, i, j+1, m, n, ans+"R");
    grid[i][j]=0;
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> grid;
    grid.clear();
    grid.resize(m, vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    cout<<f(grid, 0, 0, m, n)<<endl;

    fprint(grid, 0, 0, m, n, "");
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}

// 7 7
// 0 0 1 0 0 1 0
// 1 0 1 1 0 0 0
// 0 0 0 0 1 0 1
// 1 0 1 0 0 0 0
// 1 0 1 1 0 1 0
// 1 0 0 0 0 1 0
// 1 1 1 1 0 0 0

// 3 3
// 0 0 0
// 0 1 0
// 0 0 0