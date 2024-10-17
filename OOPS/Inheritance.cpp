#include<iostream>
using namespace std;

class Parent1{
    public:
    Parent1(){
        cout<<"I am a Parent1"<<endl;
    }
};

class Parent2{
    public:
    Parent2(){
        cout<<"I am a Parent2"<<endl;
    }
};

class Child: public Parent1,public Parent2{
    public:
    Child(){
        cout<<"I am a Child"<<endl;
    }
};

class Grand_Child: public Child{
    public:
    Grand_Child(){
        cout<<"I am a Grand-Child"<<endl;
    }
};

class Child1: public Parent2{
    public:
    Child1(){
        cout<<"I am the Child-1"<<endl;
    }
};

class Child2: public Parent2{
    public:
    Child2(){
        cout<<"I am the Child-2"<<endl;
    }
};

int main(){
    Grand_Child gc;
    return 0;
}