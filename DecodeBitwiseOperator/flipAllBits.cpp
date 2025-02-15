// Given an integer n, flip all of it's bits.

#include<iostream>
using namespace std;
int flipAllBits(int n){
    int num=n;
    num=num|(num>>1);
    num=num|(num>>2);
    num=num|(num>>4);
    num=num|(num>>8);
    num=num|(num>>16);

    return num^n;
}
int flipAllBitsUsingBrianKernighans(int n){
    int temp;
    int num=n;
    while(n>0){
        temp=n;
        n=n&(n-1);
    }
    temp=temp<<1;
    temp=temp-1;
    return temp^num;
}
int main(){
    cout<<flipAllBits(214)<<endl;
    cout<<flipAllBitsUsingBrianKernighans(214)<<endl;
    return 0;
}