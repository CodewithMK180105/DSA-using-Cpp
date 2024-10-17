// A wild pointer is a type of pointer where we declare the pointer but not initialize it.

// Due to this it ends up pointing to some random memory location

// Due to this we might get some undefined behaviour and crashes

// In some cases we might get segmentation fault

// Segmentation fault occurs when we try to access which is not available

#include<iostream>
using namespace std;
int main(){
    int *ptr; // Only declared
    cout<<ptr<<" "<<*ptr<<endl;
    return 0;
}