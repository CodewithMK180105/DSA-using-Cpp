// https://codeforces.com/problemset/problem/540/D

#include<iostream>
#include<vector>
#include<cstring>
#include<iomanip>
using namespace std;
double dpr[105][105][105];
double dps[105][105][105];
double dpp[105][105][105];
double fr(int r, int s, int p){
    if(r==0 || s==0) return 0;
    if(p==0) return 1;
    if(dpr[r][s][p]> -0.9) return dpr[r][s][p];
    int total=r*s+s*p+r*p;

    double a=fr(r, s-1, p)*((double)(r*s)/ total);
    double b=fr(r-1, s, p)*((double)(r*p)/ total);
    double c=fr(r, s, p-1)*((double)(p*s)/ total);

    return dpr[r][s][p]=a+b+c;
}
double fs(int r, int s, int p){
    if(p==0 || s==0) return 0;
    if(r==0) return 1;
    if(dps[r][s][p]> -0.9) return dps[r][s][p];
    int total=r*s+s*p+r*p;

    double a=fs(r, s-1, p)*((double)(r*s)/ total);
    double b=fs(r-1, s, p)*((double)(r*p)/ total);
    double c=fs(r, s, p-1)*((double)(p*s)/ total);

    return dps[r][s][p]=a+b+c;
}
double fp(int r, int s, int p){
    if(r==0 || p==0) return 0;
    if(s==0) return 1;
    if(dpp[r][s][p]> -0.9) return dpp[r][s][p];
    int total=r*s+s*p+r*p;

    double a=fp(r, s-1, p)*((double)(r*s)/ total);
    double b=fp(r-1, s, p)*((double)(r*p)/ total);
    double c=fp(r, s, p-1)*((double)(p*s)/ total);

    return dpp[r][s][p]=a+b+c;
}
int main(){
    int r,s,p;
    cin>>r>>s>>p;

    memset(dpr, -1, sizeof dpr);
    memset(dps, -1, sizeof dps);
    memset(dpp, -1, sizeof dpp);

    double rw=fr(r,s,p);
    double sw=fs(r,s,p);
    double pw=fp(r,s,p);

    cout<<fixed<<setprecision(15)<<rw<<" ";
    cout<<fixed<<setprecision(15)<<sw<<" ";
    cout<<fixed<<setprecision(15)<<pw<<" ";
    return 0;
}