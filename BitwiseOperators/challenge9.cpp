// Given an integers x and y, find the minimum number of the bit flips required to convert the one number to another.

#include<iostream>
using namespace std;
int main(){
    int x,y;
    cin>>x>>y;
    cout<<__builtin_popcount(x^y);
    return 0;
}