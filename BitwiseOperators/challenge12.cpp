#include<iostream>
using namespace std;
#define mod 1000000007
int main(){
    long long int fact=1;
    for(int i=1;i<25;i++){
        fact=((fact%mod)*(i%mod))%mod;
        cout<<fact<<" ";
    }
    return 0;
}