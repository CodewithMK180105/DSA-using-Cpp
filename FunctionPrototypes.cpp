#include<iostream>
using namespace std;

void fun(string);
int addition(int a,int b);

int main(){
    fun("Manishkumar");
    int response=addition(8,9);
    cout<<response;
    return 0;
}

void fun(string s){
    cout<<"Are you having fun "<<s<<"?"<<endl;
}
int addition(int a,int b){
    return a+b;
}
