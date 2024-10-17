#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void rotateMatrix(vector<vector<int>> &v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<i;j++){
            swap(v[i][j],v[j][i]);
        }
    }
    for(int i=0;i<v.size();i++) reverse(v[i].begin(),v[i].end());
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>v[i][j];
    rotateMatrix(v);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}