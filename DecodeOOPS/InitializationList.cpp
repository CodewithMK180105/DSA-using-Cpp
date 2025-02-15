#include<iostream>
using namespace std;
class Bike{
public: 
    int tyreSize;
    int engineSize;
    Bike(int ts, int es=200) : tyreSize(ts), engineSize(es) {

    }
};
int main(){
    Bike royalEnfield(15,350);
    Bike bajaj(13);

    cout<<royalEnfield.tyreSize<<" "<<royalEnfield.engineSize<<endl;
    cout<<bajaj.tyreSize<<" "<<bajaj.engineSize<<endl;
    return 0;
}