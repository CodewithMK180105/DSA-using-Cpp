#include<iostream>
using namespace std;
void func(int a=1,int z,int b=9){ // Throws an error because the convention of default argument should be from right to left
    cout<<a<<" "<<z<<" "<<b;
}
int main(){
    func(0,4);
}