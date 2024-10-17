// It is a type of a pointer that points to location that is not valid

#include<iostream>
using namespace std;
int main(){
    int *ptr=NULL;
    int i=0;
    while(i!=1){
        int x=10;
        ptr=&x;
        i++;
    }
    cout<<ptr<<endl; // Points to variable which does not exist's
    return 0;
}