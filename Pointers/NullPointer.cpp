// If we have a pointer variable which is just declared but will get addressed later  to store

// In some cases we can use NULL pointer.

// Syntax:- int *ptr=NULL; OR
// Syntax:- int *ptr=0;    OR
// Syntax:- int *ptr='\0'; 
// Here ptr is pointing to a null. Hence, it is called as NULL pointer

// Problem :- Runtime error may occur while dereferencing the null pointers.

#include<iostream>
using namespace std;
int main(){
    int *p1=NULL;
    int *p2=0;
    int *p3='\0';
    cout<<p1<<" "<<p2<<" "<<p3<<endl;
    // cout<<*p1<<" "<<*p2<<" "<<*p3<<endl;
    return 0;
}