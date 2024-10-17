#include<iostream>
using namespace std;
int main(){
    int n1=5;  // 0101
    cout<<~n1<<endl;
    int n2=8;  // 1000
    cout<<~n2<<endl;

    cout<<(n1<<4)<<endl; // Left-shift (Multiply by 2 raise to 1)
    cout<<(n1>>1)<<endl; // Right-shift (Divide by 2 raise to 1)

    cout<<(n1&n2)<<endl;  // 0
    cout<<(n1|n2)<<endl;  // 1101 = 13
    cout<<(n1^n2)<<endl;  // 1101
    cout<<~(n1^n2)<<endl;  // 0010
    return 0;
}