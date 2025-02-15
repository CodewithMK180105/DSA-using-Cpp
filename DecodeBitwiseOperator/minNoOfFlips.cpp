// Calculate the minimum number of the bit flips required to convert from one number to another.
// eg: 5 can be written as 0101 and,
//     11 can be written as 1011, so the number of bit flips required is 3.


#include<iostream>
using namespace std;
int countdifferentBits(int m, int n){
    int xr=m^n;
    return __builtin_popcount(xr);
}
int main(){
    cout<<countdifferentBits(5,11)<<endl;
    cout<<countdifferentBits(23,32)<<endl;
    return 0;
}

// 010111
// 100000