#include<iostream>
#include<cmath>
using namespace std;
bool isPrime1(int n){ // O(n)
    if(n==1) return false;
    for(int i=2;i<n;i++){
        if(n%i==0) return false;
    }
    return true;
}
bool isPrime2(int n){ // O(sqrt(n))
    if(n==1) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    cout<<isPrime1(41)<<endl;
    cout<<isPrime2(41)<<endl;
    return 0;
}