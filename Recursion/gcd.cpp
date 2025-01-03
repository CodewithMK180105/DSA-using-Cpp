#include<iostream>
using namespace std;
int gcd(int n1,int n2){
    if(n2>n1) return gcd(n2,n1);
    if(n2==0) return n1;
    gcd(n2,n1%n2);
}
int main(){
    int n1,n2; cin>>n1>>n2;
    cout<<gcd(n1,n2);
}

// TC=> O(log(a+b))