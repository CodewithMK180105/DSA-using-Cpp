#include<iostream>
using namespace std;
class Vehicle{
    public:
        int topSpeed;
        float mileage;
        string fuel;
};
class twoWheelVehicle: public Vehicle{
    public:
        int tyres=2;
        int maxHumanCapacity=3;
};
class Scooty: public twoWheelVehicle{
    public:
    int bootSpace;
};
class Bike: public twoWheelVehicle{
    public:
    int gearSpeed;
};
int main(){

}