#include<iostream>
#include<vector>
using namespace std;
int rectangleSum(vector<vector<int>> &matrix,int l1,int r1,int l2,int r2){
    int sum=0;
    for(int i=0;i<matrix.size();i++){
        for(int j=1;j<=matrix[i].size();j++){
            matrix[i][j]+=matrix[i][j-1];
        }
    }
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++) cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    for(int i=l1;i<=l2;i++){
        if(r1!=0){
            sum+=matrix[i][r2]-matrix[i][r1-1];
        }
        else{
            sum+=matrix[i][r2];
        }
    }
    return sum;
}
int main(){
    int m,n; cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>matrix[i][j];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    int l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    int sum=rectangleSum(matrix,l1,r1,l2,r2);
    cout<<sum;
    return 0;
}