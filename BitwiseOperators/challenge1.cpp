// Check if a number is odd or even without using the '%' sign.

#include<iostream>
#include<bitset>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    if(n&1==1){
        cout<<"The number is Odd";
    } else{
        cout<<"The number is Even";
    }
    return 0;
}

// Approach to solve:
// Every odd number when converted to binary has 1 as it's last(least significant) bit.
// So when we AND odd number with the 1 we get the output to be as 0...01