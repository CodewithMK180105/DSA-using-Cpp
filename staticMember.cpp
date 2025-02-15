#include<iostream>
using namespace std;
void print(){
    static int a=10;
    cout<<a<<endl;
    a++;
}
int main(){
    print();
    print();
    print();
    print();
    print();
    return 0;
}