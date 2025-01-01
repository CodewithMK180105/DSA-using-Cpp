// Given a positive integer, return if it is a power a three.

#include<iostream>
using namespace std;
bool powerOfTwo(int n){
    if(n<=0) return false;
    if(n==1) return true;
    if(n%3!=0) return false;
    return powerOfTwo(n/3);
}
int main(){
    cout<<powerOfTwo(243)<<endl;
    return 0;
}