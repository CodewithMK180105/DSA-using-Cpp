#include<iostream>
#include<cmath>
using namespace std;
void printFactors1(int n){ // O(n)
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
}
void printFactors2(int n){ // O(sqrt(n)) {But the factors are not sorted}
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(i!=n/i) cout<<i<<" "<<n/i<<" ";
            else cout<<i<<" ";
        }
    }
}
void printFactors3(int n){ // O(2*sqrt(n)) {Here the factors are sorted}
    for(int i=1;i<sqrt(n);i++){
        if(n%i==0){
            cout<<i<<" ";
        }
    }
    for(int i=sqrt(n);i>=1;i--){
        if(n%i==0){
            cout<<n/i<<" ";
        }
    }
}
int main(){
    printFactors1(60);
    cout<<endl;
    printFactors2(60);
    cout<<endl;
    printFactors3(60);


    // printFactors1(49);
    // cout<<endl;
    // printFactors2(49);
    // cout<<endl;
    // printFactors3(49);
    return 0;
}