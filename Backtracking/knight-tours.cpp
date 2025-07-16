#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> dir={{-1, -2}, {-2, -1}, {1,2}, {2,1}, {-1, 2}, {2, -1}, {1, -2}, {-2, 1}};
vector<vector<int>> grid;
bool isSafe(int r, int c, int n){
    return r>=0 and c>=0 and r<n and c<n and grid[r][c]==-1;
}
void display(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\n\n";
}
void f(int r, int c, int n, int count){
    if(count==n*n-1){
        grid[r][c]=count;
        display(n);
        cout<<"*****\n\n"<<endl;
        grid[r][c]=-1;
        return;
    }

    for(int d=0;d<8;d++){
        int nr=r+dir[d][0], nc=c+dir[d][1];
        if(isSafe(nr, nc, n)){
            grid[r][c]=count;
            f(nr, nc, n, count+1);
            grid[r][c]=-1;
        }
    }
}
void knightTours(int n){
    int r,c;
    cout<<"Enter the starting row and starting column: ";
    cin>>r>>c;
    grid.clear();
    grid.resize(n, vector<int>(n, -1));
    f(r,c,n,0);
}
int main(){
    cout<<"Enter the size of the board: ";
    int n; cin>>n;
    knightTours(n);
}