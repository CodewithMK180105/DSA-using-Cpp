#include<iostream>
using namespace std;

int Dec_Bin(int n){
    int ans=0,rem,ten_power=1;
    while(n>0){
        int rem=n%2;
        ans=ans+rem*ten_power;
        ten_power*=10;
        n/=2;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter a Decimal number : ";
    cin>>n;
    cout<<Dec_Bin(n);
    return 0;
}