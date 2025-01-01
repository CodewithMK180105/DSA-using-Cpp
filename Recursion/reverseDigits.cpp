// Calculate the reverse of a number using the recursion.

#include<iostream>
using namespace std;
void reverseNumber(int n){
    if(n==0) return;
    cout<<n%10;
    reverseNumber(n/10);
}
void reverseNumber2(int r,int n){
    if(n==0){
        cout<<r;
        return;
    }
    r=(r*10)+(n%10);
    return reverseNumber2(r,n/10);
}
int main(){
    reverseNumber(154783);
    cout<<endl;
    reverseNumber2(0,154);
    return 0;
}

// 154 => reverseNumber(15)
// 15 => reverseNumber(1)
// 1 => reverseNumber(0)
