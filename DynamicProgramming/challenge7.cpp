// https://www.hackerearth.com/practice/algorithms/dynamic-programming/linear/practice-problems/algorithm/roy-and-coin-boxes-1/

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> F(n+1);
    int m;
    cin>>m;
    vector<int> L(n+1);
    vector<int> R(n+1);
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        L[l]++; R[r]++;
    }

    F[1]=L[1];
    for(int i=2;i<n+1;i++){
        F[i]=L[i]+F[i-1]-R[i-1];
    }
    vector<int> c(m+1);
    for(int i=0;i<n+1;i++){
        c[F[i]]++;
    }

    int noq;
    cin>>noq;
    vector<int> queries;
    for(int i=0;i<noq;i++){
        int q;
        cin>>q;
        queries.push_back(q);
    }

    for(int i=(m+1)-2;i>=0;i--){
        c[i]+=c[i+1];
    }

    for(int i=0;i<noq;i++){
        if(queries[i]>m) cout<<0<<endl;
        else cout<<c[queries[i]]<<endl;
    }
    return 0;
}