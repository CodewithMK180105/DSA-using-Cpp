#include<iostream>
using namespace std;
class Loading{
    public:
        void sum(string a, string b){
            cout<<a+b<<endl;
        }
        void sum(int a, int b){
            cout<<a+b<<endl;
        }
        void sum(int a, int b,int c){
            cout<<a+b+c<<endl;
        }
};
int main(){
    Loading a;
    a.sum("Hello","World");
    a.sum(2,3);
    a.sum(4,5,6);
    return 0;
}