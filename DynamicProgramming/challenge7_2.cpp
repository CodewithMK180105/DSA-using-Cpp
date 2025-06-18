// https://www.hackerearth.com/practice/algorithms/dynamic-programming/linear/practice-problems/algorithm/roy-and-coin-boxes-1/

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> F(n+2);
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        F[l]++;
        F[r+1]--;
    }

    // for(int i=0;i<n+2;i++){
    //     cout<<F[i]<<" ";
    // } cout<<endl;

    // Prefix sum
    for(int i=1;i<n+1;i++){
        F[i]+=F[i-1];
    }

    vector<int> coins(m+1);
    for(int i=1;i<n+1;i++){
        coins[F[i]]++;
    }

    for(int i=(m+1)-2;i>=0;i--){
        coins[i]+=coins[i+1];
    }

    // for(int i=0;i<m+1;i++){
    //     cout<<coins[i]<<" ";
    // } cout<<endl;

    int noq;
    cin>>noq;
    vector<int> queries;
    for(int i=0;i<noq;i++){
        int q;
        cin>>q;
        queries.push_back(q);
    }

    for(int i=0;i<noq;i++){
        if(queries[i]>m) cout<<0<<endl;
        else cout<<coins[queries[i]]<<endl;
    }

    return 0;
}