// Given a boolean 2D array, where each row is sorted. Find the row 
// with maximum number of 1's

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int maximumOnesRow(vector<vector<int>> &v){
    int maxOnes=INT_MIN;
    int maxRow=-1;
    int columns=v[0].size();
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]==1){
                int currOnes=columns-j;
                if(currOnes>maxOnes){
                    maxOnes=currOnes;
                    maxRow=i;
                }
                break;
            }
        }
    }
    return maxRow;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>v[i][j];
    int res=maximumOnesRow(v);
    cout<<res;
    return 0;
}