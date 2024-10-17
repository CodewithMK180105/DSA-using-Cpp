#include<iostream>
using namespace std;
class Scooty{
    public:
        int topSpeed;
        float mileage;
        virtual void sound(){
            cout<<"Beep Beep"<<endl;
        }
    private:
        int bootspace;
};
class Bike: public Scooty{
    public:
        int gears;
        void sound(){
            cout<<"Vroom Vroom"<<endl;
        }
};
class SuperBike: public Scooty{
    public:
        int gears;
        void sound(){
            cout<<"Broom Broom"<<endl;
        }
};
int main(){
    Scooty* b=new Bike(); // Base class reference child class object
    b->sound();
    Scooty* b2=new SuperBike(); //
    b2->sound();
    return 0;
}