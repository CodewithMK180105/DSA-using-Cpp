// You are given an m x n grid rooms initialized with these three possible values:

// -1 → A wall or an obstacle.

// 0 → A gate.

// INF → Infinity, meaning an empty room.
// We use the value 2^31 - 1 = 2147483647 to represent INF.

// Goal:
// Fill each empty room with the distance to its nearest gate.
// If it is impossible to reach a gate, it should be filled with INF.

#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;
#define inf INT_MAX
vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
int main(){
    vector<vector<int>> rooms={{inf, -1, 0, inf}, {inf, inf, inf, -1}, {inf, -1, inf, -1}, {0, -1, inf, inf}};
    int m=rooms.size(), n=rooms[0].size();

    vector<vector<bool>> vis(m, vector<bool>(n, false));
    queue<pair<int, int>> qu;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(0==rooms[i][j]) {
                qu.push({i,j});
                vis[i][j]=true;
            }
        }
    }
    
    qu.push({-1, -1});
    int dist=0;

    while(!qu.empty()){
        auto cell=qu.front();
        int i=cell.first;
        int j=cell.second;
        rooms[i][j]=dist;
        qu.pop();
        if(i==-1 && j==-1){
            if(!qu.empty()){
                qu.push({-1, -1});
                dist++;
            } else break;
        }

        for(int d=0;d<4;d++){
            int nr=i+dir[d][0];
            int nc=j+dir[d][1];

            if(nr<0 || nc<0 || nr>=m || nc>=n) continue;
            if(-1==rooms[nr][nc]) continue;
            if(0==rooms[nr][nc]) continue;
            if(true==vis[nr][nc]) continue;

            qu.push({nr,nc});
            vis[nr][nc]=true;
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(inf==rooms[i][j]) {
                cout<<"inf"<<" ";
            } else cout<<rooms[i][j]<<" ";
        }
        cout<<endl;
    }    
    return 0;
}