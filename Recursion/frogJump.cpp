#include<iostream>
using namespace std;
int calculate(int n,int *h,int i){
    if(i==n-1) return 0;
    if(i==n-2) return calculate(n,h,i+1)+abs(h[i]-h[i+1]);
    return min(calculate(n,h,i+1)+abs(h[i]-h[i+1]),calculate(n,h,i+2)+abs(h[i]-h[i+2]));
}
int main(){
    cout<<"Enter the no. of stones : ";
    int n; cin>>n;
    int h[n];
    for(int i=0;i<n;i++) cin>>h[i];
    cout<<calculate(n,h,0);
}