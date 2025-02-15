#include<iostream>
using namespace std;
class Bike {
public:
    int tyreSize;
    int engineSize;
    Bike(int tyreSize, int engineSize){  // This is constructor
        this->tyreSize=tyreSize;
        this->engineSize=engineSize;
        cout<<"Constructor call Hua"<<endl;
    }
    ~Bike(){  // This is destructor (Used to free the memory) get called whenever the object goes out of the scope
        cout<<"Destructor call Hua"<<endl;
    }
    void printDetails(){
        cout<<this->tyreSize<<" "<<this->engineSize<<endl;
    }
};
int main(){
    Bike tvs(12, 100);
    Bike honda(13, 150);
    Bike royalEnfield(15, 350);

    bool flag=true;
    if(flag){
        Bike bmw(20,300);
        bmw.printDetails();
    }

    tvs.printDetails();
    honda.printDetails();
    royalEnfield.printDetails();
    return 0;
}