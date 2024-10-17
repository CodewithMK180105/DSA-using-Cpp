#include<iostream>
using namespace std;
class Scooty{
    public:
        int topSpeed;
        float mileage;
    private:
        int bootspace;
};
class Bike:public Scooty{
    public:
        int gears;
};
int main(){
    Bike b;
    b.topSpeed =180;
    b.mileage =12.5;
    b.gears =6;
    // b.bootspace =5; // bootspace cannot be accessed
    return 0;
}