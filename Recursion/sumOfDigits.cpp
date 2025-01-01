// Calculate the sum of digits using recursion.

#include<iostream>
using namespace std;
int sum(int n){  // return type
    if(n==0) return 0;
    int rem=n%10;
    return rem+sum(n/10);
}
void sum2(int s,int n){  // paramaterised
    if(n==0){
        cout<<s;
        return;
    }
    return sum2(s+(n%10),n/10);
}
int main(){
    cout<<sum(6446)<<endl;
    sum2(0,555);
    return 0;
}