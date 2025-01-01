// Find the total number of ways to reach from that start state(1,1) to destination (n,n) in a 2D grid.
// Also write a separate a function to print all that paths.

#include<iostream>
using namespace std;
int gridPath(int sr,int sc,int er,int ec){
    if(sr==er) return 1;
    if(sc==ec) return 1;
    int rightWays=gridPath(sr,sc+1,er,ec);
    int downWays=gridPath(sr+1,sc,er,ec);
    return rightWays+downWays;
}
void printPath(int sr,int sc,int er,int ec,string s){
    if (sr > er || sc > ec) return;
    if(sc==ec && sr==er){
        cout<<s<<endl;
        return;
    }
    printPath(sr,sc+1,er,ec,s+"R"); //right
    printPath(sr+1,sc,er,ec,s+"D"); //down
}
int main(){
    printPath(1,1,3,3,"");
    return 0;
}