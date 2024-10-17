// Given a number n. Find the sum of natural numbers till 'n' but with alternate signs

// That means if n=5 then you have to return 1-2+3-4+5=3

#include<iostream>
using namespace std;
int challenge_Complexity_N(int n){
    if(n<1) return 0;
    int sum=challenge_Complexity_N(n-1);
    if(n%2==0) sum-=n;
    else sum+=n;
    return sum;
}
int challenge_Complexity_1(int n){
    if(n%2==0) return -n/2;
    else return n/2+1;
}
int main(){
    int n; cin>>n;
    cout<<challenge_Complexity_N(n)<<endl;
    cout<<challenge_Complexity_1(n);
}