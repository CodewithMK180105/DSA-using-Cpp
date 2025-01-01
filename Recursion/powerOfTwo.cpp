// Given a positive integer, return if it is a power a two.

#include<iostream>
using namespace std;
bool powerOfTwo(int n){
    if(n<=0) return false;
    if(n==1) return true;
    if(n%2!=0) return false;
    return powerOfTwo(n/2);
}
int main(){
    cout<<powerOfTwo(6);
    return 0;
}