// Q1.
// Given a grid of n x m size. Every cell of the grid is marked as 'L', 'R', 'U', 'D'.
// Character on a cell denotes — if you are standing at that cell, what direction you can move to.

// Check if we start from (0, 0), can we reach (n - 1, m - 1)?

// → Space → O(1)
// → grid is non modify

// R  R  D  R
// D  L  D  L
// U  D  L  D
// U  R  R  R

// Direction Meaning (diagram):
// U → move up
// D → move down
// L → move left
// R → move right

// Recursion with O(m*n) complexity
// Why DP doesn’t help here:
// From each cell, there is only one deterministic direction to move.

// You don’t have multiple paths to choose from → no overlapping subproblems.
#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

bool f(int i, int j, vector<vector<char>>& grid, int &m, int &n, vector<vector<bool>>& vis){
    if(i<0 || j<0 || i>=m || j>=n) return false;
    if(i==m-1 && j==n-1) return true;
    if(vis[i][j]==true) return false;

    vis[i][j]=true;

    if(grid[i][j]=='D') return f(i+1, j, grid, m, n, vis);
    if(grid[i][j]=='U') return f(i-1, j, grid, m, n, vis);
    if(grid[i][j]=='R') return f(i, j+1, grid, m, n, vis);
    if(grid[i][j]=='L') return f(i, j-1, grid, m, n, vis);
}

bool f2(int i, int j, vector<vector<char>>& grid, int &m, int &n, int stepsCount){
    if(i<0 || j<0 || i>=m || j>=n) return false;
    if(i==m-1 && j==n-1) return true;
    if(stepsCount>=m*n) return false;

    if(grid[i][j]=='D') return f2(i+1, j, grid, m, n, stepsCount+1);
    if(grid[i][j]=='U') return f2(i-1, j, grid, m, n, stepsCount+1);
    if(grid[i][j]=='R') return f2(i, j+1, grid, m, n, stepsCount+1);
    if(grid[i][j]=='L') return f2(i, j-1, grid, m, n, stepsCount+1);
}

bool f3(int i, int j, vector<vector<char>>& grid, int &m, int &n, int stepsCount){
    while(true){
        if(i<0 || j<0 || i>=m || j>=n) return false;
        if(i==m-1 && j==n-1) return true;
        if(stepsCount>=m*n) return false;

        stepsCount++;
        if(grid[i][j]=='D') i++;
        else if(grid[i][j]=='U') i--;
        else if(grid[i][j]=='R') j++;
        else if(grid[i][j]=='L') j--;
        else return false; // Invalid character
    }
}

pair<int, int> incrementPointer(int i, int j, vector<vector<char>>& grid, int &m, int &n){
    if(i<0 || j<0 || i>=m || j>=n) return {-1, -1};

    if(grid[i][j]=='R') j++;
    else if(grid[i][j]=='L') j--;
    else if(grid[i][j]=='U') i--;
    else if(grid[i][j]=='D') i++;
    else return {-1, -1};

    if(i<0 || j<0 || i>=m || j>=n) return {-1, -1};
    return {i,j};
}
bool f4(int i, int j, vector<vector<char>>& grid, int &m, int &n){
    int si=0,sj=0; // slow pointers
    int fi=0,fj=0; // fast pointers

    while(true){
        // execute the slow pointer for the once
        tie(si, sj)= incrementPointer(si, sj, grid, m, n);
        if(si==-1 && sj==-1) return false;
        
        // execute the fast pointer for the twice
        tie(fi, fj)= incrementPointer(fi, fj, grid, m, n);
        if(fi==-1 && fj==-1) return false;
        tie(fi, fj)= incrementPointer(fi, fj, grid, m, n);
        if(fi==-1 && fj==-1) return false;

        if((si==m-1 && sj==n-1)||(fi==m-1 && fj==n-1)){ // final state reached
            return true; 
        }

        if(si==fi && sj==fj) return false; //cycle detected
    }
}
int main(){
    vector<vector<char>> grid={
        {'R', 'R', 'D', 'R'}, 
        {'D', 'L', 'D', 'L'}, 
        {'U', 'D', 'L', 'D'}, 
        {'U', 'R', 'R', 'R'}
    };
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    cout<<f(0, 0, grid, m, n, vis)<<endl;
    cout<<f2(0, 0, grid, m, n, 0)<<endl;
    cout<<f3(0, 0, grid, m, n, 0)<<endl;
    cout<<f4(0, 0, grid, m, n)<<endl;
    return 0;
}


