// Find the total number of ways to reach from that start state(1,1) to destination (n,n) in a 2D grid.
// Also write a separate a function to print all that paths.

#include<iostream>
using namespace std;
int gridPath(int er,int ec){
    if(1==ec || 1==er) return 1;
    int rightWays=gridPath(er,ec-1);
    int downWays=gridPath(er-1,ec);
    return rightWays+downWays;
}
void printPath(int er,int ec,string s){
    if (er<0 || ec<0) return;
    if(1==ec && 1==er){
        cout<<s<<endl;
        return;
    }
    printPath(er,ec-1,s+"R"); //right
    printPath(er-1,ec,s+"D"); //down
}
int main(){
    printPath(3,3,"");
    return 0;
}