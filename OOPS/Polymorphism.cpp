// Ability to express an object or a method in different forms

#include<iostream>
using namespace std;

class Sum{
    public:
    void sum(int a,int b){
        cout<<a+b<<endl;
    }
    void sum(int a,int b,int c){
        cout<<a+b+c<<endl;
    }
    void sum(float a,float b){
        cout<<a+b<<endl;
    }
};

int main(){
    Sum s;
    s.sum(3,4);
    s.sum(2,5,8);
    s.sum(8.1f,2.4f);
    return 0;
}