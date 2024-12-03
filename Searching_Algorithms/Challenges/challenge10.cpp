// Search the target value in a 2D matrix of the dimensions mxn and return 1 if found, else return 0. This matrix has the following properties: 
// 1. Integers in each row are sorted from left to right.
// 2. The first integer of each row is greater the last integer of the previous row.

// Input: [[1,3,5,7],[10,11,16,20],[23,30,34,60]] ===> target=3
// Output: 1

#include<iostream>
#include<vector>
using namespace std;
int searchInMatrix(vector<vector<int>>& v,int target){
    int m=v.size(),n=v[0].size();
    int low=0,high=m*n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int x=mid/n;
        int y=mid%n;
        if(v[x][y]==target){
            return 1;
        } else if(v[x][y]<target){
            low=mid+1;
        } else{
            high=mid-1;
        }
    }
    return 0;
}
int main(){
    vector<vector<int>> v={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target; cin>>target;
    cout<<searchInMatrix(v,target);
    return 0;
}