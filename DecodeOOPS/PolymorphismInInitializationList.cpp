#include<iostream>
using namespace std;
class Bike {
public:
    int tyreSize;
    int engineSize;

    Bike(int ts, int es): tyreSize(ts), engineSize(es) {}
    Bike(int ts): tyreSize(ts), engineSize(100) {}
    Bike(): tyreSize(12), engineSize(100) {}

    void display() {
        cout << "Tyre Size: " << tyreSize << ", Engine Size: " << engineSize << endl;
    }
    
};
int Area(int l, int b){
    return l*b;
}
float Area(int r){
    return 3.142*r*r;
}
int main(){
    Bike royalEnfield(15, 350);
    Bike bajaj(13);

    royalEnfield.display();
    bajaj.display();

    cout<<Area(5)<<endl;
    cout<<Area(5,3)<<endl;
    return 0;
}