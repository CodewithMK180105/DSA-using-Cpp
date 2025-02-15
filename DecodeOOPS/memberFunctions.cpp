#include<iostream>
using namespace std;
class Calculator{
private:
    int a;
    int b;
public:
    void add(){
        cout<<"Addition "<<a+b<<endl;
    }
    void subtract(){
        cout<<"Subtraction "<<a-b<<endl;
    }
};
int main(){
    Calculator cal;
    cal.add();
    return 0;
}