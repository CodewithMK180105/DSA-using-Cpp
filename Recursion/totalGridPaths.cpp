#include<iostream>
using namespace std;
int gridPath(int m,int n,int i,int j){
    if(i==m-1 && j==n-1) return 1;
    else if(i==m-1 || j==n-1) return 1;
    return gridPath(m,n,i+1,j)+gridPath(m,n,i,j+1);
}
int main(){
    int m,n; cin>>m>>n;
    cout<<gridPath(m,n,0,0);
    return 0;
}