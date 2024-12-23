// Swap the 2 numbers without using the third variable.

// Approach 1: using the '+' and '-' operator.

#include<iostream>
using namespace std;
void swapUsingArithmeticOperators(int &a,int &b){
    a=a+b; // a=5+7=12
    b=a-b; // b=12-7=5
    a=a-b; // a=12-5=7
    cout<<"Swapped using arithmetic operator"<<endl;
}
void swapUsingBitwiseOperators(int &a,int &b){
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<"Swapped using bit operator"<<endl;
}
int main(){
    int a=5,b=7;
    cout<<a<<" "<<b<<endl;
    swapUsingBitwiseOperators(a,b);
    cout<<a<<" "<<b;
}