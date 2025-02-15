// Given an integer n, find the maximum power of the 2 smaller than n.

#include<iostream>
using namespace std;
int maxPowerSmallerThanEqualToNum(int num){
    int temp;
    while(num>0){
        temp=num;
        num=(num)&(num-1);
    }
    return temp;
}
int maxPowerSmallerThanNum(int num){
    if((num & (num-1))==0) return num>>1;
    int temp;
    while(num>0){
        temp=num;
        num=(num)&(num-1);
    }
    return temp;
}
int maxPowerGreaterThanEqualToNum(int num){
    int temp;
    while(num>0){
        temp=num;
        num=(num)&(num-1);
    }
    return 2*temp;
}
int maxPowerGreaterThanNum(int num){
    if((num & (num-1))==0) return num<<1;
    int temp;
    while(num>0){
        temp=num;
        num=(num)&(num-1);
    }
    return 2*temp;
}
int main(){
    cout<<maxPowerSmallerThanEqualToNum(24)<<endl;
    cout<<maxPowerSmallerThanNum(24)<<endl;
    cout<<maxPowerGreaterThanEqualToNum(24)<<endl;
    cout<<maxPowerGreaterThanNum(24)<<endl;
    return 0;
}