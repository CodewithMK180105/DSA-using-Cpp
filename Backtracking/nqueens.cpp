#include<iostream>
#include<vector>
using namespace std;

vector<vector<char>> grid;
vector<vector<string>>  res;

bool canPlaceQueen(int col, int row, int n){
    // check for the column
    for(int i=row-1;i>=0;i--){
        if(grid[i][col]=='Q') return false;
    }
    
    // check for the left-diagonal
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
        if(grid[i][j]=='Q') return false;
    }

    // check for the right-diagonal
    for(int i=row-1, j=col+1; i>=0 && j<n;i--, j++){
        if(grid[i][j]=='Q') return false;
    }

    return true;
}

void f(int row, int n){
    if(row==n){
        vector<string> temp;
        for(int i=0;i<n;i++){
            string str="";
            for(int j=0;j<n;j++){
                str+=grid[i][j];
            }
            temp.push_back(str);
        }
        res.push_back(temp);
        return;
    }

    for(int col=0;col<n;col++){
        if(canPlaceQueen(col, row, n)){
            grid[row][col]='Q';
            f(row+1,n);
            grid[row][col]='.';
        }
    }
}

vector<vector<string>> nqueen(int n){
    grid.clear();
    res.clear();
    grid.resize(n, vector<char>(n,'.'));
    f(0, n);
    return res;
}
int main(){
    nqueen(4);
    return 0;
}