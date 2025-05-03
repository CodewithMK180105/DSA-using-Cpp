// Given an integer n, flip all the bits, if the given bit is 1, change it to 0 and vice versa.

#include<iostream>
using namespace std;
int maxPowerOfTwo(int n){
    int temp=0;
    while(n>0){
        temp=n;
        n=n&(n-1);
    }
    return temp;
}
int main(){
    int n;
    cin>>n;
    int m=maxPowerOfTwo(n);
    int x=(m<<1)-1;
    int y=n^x;
    cout<<y;
    return 0;
}

