// https://atcoder.jp/contests/dp/tasks/dp_i

#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
vector<vector<double>> dp(3000, vector<double>(3000, -1));
double prob(vector<double> &p, int i, int n, int hcount){
    if (i == n) return (hcount > n / 2) ? 1.0 : 0.0;

    if(dp[i][hcount] > -0.9) return dp[i][hcount];

    return dp[i][hcount]=prob(p, i+1, n, hcount+1)*p[i]+prob(p, i+1, n, hcount)*(1-p[i]);
}
int main(){
    int n; cin>>n;
    vector<double> v;
    for(int i=0;i<n;i++){
        double x; cin>>x;
        v.push_back(x);
    }
    cout<<fixed<<setprecision(10)<<prob(v, 0, n, 0);
    return 0;
}