// Matrix Chain Multiplication
// Given the dimension of a sequence of matrices in an array arr[], 
// where the dimension of the i-th matrix is (arr[i - 1] * arr[i]),
// the task is to find the most efficient way to multiply these matrices 
// together such that the total number of element multiplications is minimum.

// --------------------------------------------------
// Input 1:
// arr[] = {40, 20, 30, 10, 30}

// Output 1:
// 26000

// Explanation:
// There are 4 matrices of dimensions:
// A: 40×20
// B: 20×30
// C: 30×10
// D: 10×30

// The minimum number of multiplications is obtained by putting 
// parentheses in the following way:
// A(BC)D

// The minimum is calculated as:
// Step 1: Multiply B and C -> 20*30*10 = 6000
// Step 2: Multiply A with result of (BC) -> 40*20*10 = 8000
// Step 3: Multiply result with D -> 40*10*30 = 12000
// Total = 6000 + 8000 + 12000 = 26000

// --------------------------------------------------
// Input 2:
// arr[] = {1, 2, 3, 4, 3}

// Output 2:
// 30

// Explanation:
// There are 4 matrices of dimensions:
// A: 1×2
// B: 2×3
// C: 3×4
// D: 4×3

// The minimum number of multiplications is obtained by putting 
// parentheses in the following way:
// ((AB)C)D

// The minimum is calculated as:
// Step 1: Multiply A and B -> 1*2*3 = 6
// Step 2: Multiply result with C -> 1*3*4 = 12
// Step 3: Multiply result with D -> 1*4*3 = 12
// Total = 6 + 12 + 12 = 30


#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<vector<int>> dp;
int recMemo(int i, int j, vector<int> v){
    if(i+1==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int ans=INT_MAX;
    for(int k=i+1;k<j;k++){
        ans=min(ans, recMemo(i, k, v)+recMemo(k, j, v)+(v[i]*v[j]*v[k]));
    }
    return dp[i][j]=ans;
}
int tabulation(int n, vector<int> v){
    vector<vector<int>> tb(n, vector<int>(n));
    for(int len=2;len<n;len++){
        for(int i=1;i+len-1<n;i++){
            int j=i+len-1;
            tb[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                tb[i][j]=min(tb[i][j], tb[i][k]+tb[k+1][j]+(v[i-1]*v[k]*v[j]));
            }
        }
    }
    return tb[1][n-1];
}
int main(){
    vector<int> v={4,2,3,1,3};
    int n=v.size();
    dp.clear();
    dp.resize(n, vector<int>(n, -1));
    // cout<<recMemo(0, n-1, v);
    cout<<tabulation(n, v);
    return 0;
}