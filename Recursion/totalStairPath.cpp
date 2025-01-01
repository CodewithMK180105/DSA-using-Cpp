// Given a stair(stair count), a person can climb either one stair or two stair and their combination. Find the total number of way to climb the stairs.

#include<iostream>
using namespace std;
int stairs(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    return stairs(n-1)+stairs(n-2);
}
int main(){
    cout<<stairs(6);
}