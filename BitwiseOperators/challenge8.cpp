// Given an integer n, find the maximum power of the two that is smaller than equal n.
// Given an integer n, find the minimum power of the two that is greater than n.

#include<iostream>
using namespace std;
int minPower(int n){
    int temp;
    while(n){
        temp=n;
        n=n&(n-1);
    }
    return temp;
}
int minPower2(int n){
    n=n|(n>>1);
    n=n|(n>>2);
    n=n|(n>>4);
    n=n|(n>>8);
    n=n|(n>>16);

    return (n+1)/2;
}
int main(){
    int n; cin>>n;
    int minpower=minPower2(n    );
    cout<<"Maximum power of 2 smaller than "<<n<<" is "<<minpower<<endl;
    cout<<"Minimum power of 2 greater than "<<n<<" is "<<2*minpower<<endl;
    return 0;
}