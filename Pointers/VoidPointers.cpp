// These are the special type of pointer's that can point to any datatype value

// void pointers can't be dereferenced directly
// However, it can be dereferenced by applying typecasting

#include<iostream>
using namespace std;
int main(){
    float f=10.2;
    int x=10;
    void *ptr=&f;
    float *floatPointer = (float *)ptr;
    cout<<*floatPointer<<endl;
    ptr=&x;
    int *integerPointer = (int *)ptr;
    cout<<*integerPointer<<endl;
    return 0;
}