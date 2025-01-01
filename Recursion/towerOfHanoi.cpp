// Write a program to give the output as the steps to solve the problem of the tower of hanoi for n slabs.

#include<iostream>
using namespace std;
void towerOfHanoi(int n, char s, char h, char d){
    if(n==0) return;
    towerOfHanoi(n-1,s,d,h);
    cout<<s<<"->"<<d<<endl;
    towerOfHanoi(n-1,h,s,d);
}
int main(){
    towerOfHanoi(8,'A','B','C');
    return 0;
}