// 1197. Minimum Knight Moves

// Medium 👍 1434 👎 394 📌 Add to List 🔗 Share

// In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].

// A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.

// [Image showing the 8 possible knight moves]

// Return the minimum number of steps needed to move the knight to the square [x, y]. It is guaranteed the answer exists.


#include<iostream>
#include<climits>
#include<vector>
#include<queue>
#include<set>
using namespace std;
vector<vector<int>> dir={{-1,-2}, {-1,2}, {1,2}, {1,-2}, {-2,-1}, {-2,1}, {2,1}, {2,-1}};
set<pair<int, int>> st;
int main(){
    int x,y;
    cin>>x>>y;
    x=abs(x);
    y=abs(y);
    queue<pair<int, int>> qu;
    qu.push({0,0});
    st.insert({0, 0});
    qu.push({-1,-1});
    int minSteps=0;

    while(!qu.empty()){
        auto cell=qu.front();
        int i=cell.first;
        int j=cell.second;
        qu.pop();
        if(i==-1 && j==-1){
            if(!qu.empty()){
                minSteps++;
                qu.push({-1, -1});
            }
        } else if(i==x && j==y){
            break;
        }
        for(int d=0;d<8;d++){
            int nr=i+dir[d][0];
            int nc=j+dir[d][1];

            if(st.count({nr,nc})) continue;
            qu.push({abs(nr), abs(nc)});
            st.insert({abs(nr),abs(nc)});
        }
    }
    cout<<minSteps;
    return 0;
}