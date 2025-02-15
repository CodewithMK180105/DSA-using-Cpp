// Find the number of set bits in the binary number.

#include<iostream>
using namespace std;

int countSetBits(int num){
    int count=0;
    while(num>0){
        num=(num)&(num-1);
        count++;
    }
    return count;
}
 
int main(){
    cout<<__builtin_popcount(453)<<endl;
    cout<<countSetBits(453);
    return 0;
}