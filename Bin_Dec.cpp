#include<iostream>
using namespace std;

int Bin_Dec(int n){
    int two_power=1;
    int ans=0;
    while(n>0){
        int lastdigit= n%10;
        ans=ans+lastdigit*two_power;
        two_power*=2;
        n/=10;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter a Binary number : ";
    cin>>n;
    cout<<Bin_Dec(n);
    return 0;
}