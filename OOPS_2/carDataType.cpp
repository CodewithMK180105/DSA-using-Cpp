// Passing the object as a parameter in a function

#include<iostream>
using namespace std;

class Car{
    public:
    string name;
    int price;
    int seats;
    string type;
};

void printDetail(Car c){
    cout<<"Name: "<<c.name<<endl;
    cout<<"Price: "<<c.price<<endl;
    cout<<"Seats: "<<c.seats<<endl;
    cout<<"Type: "<<c.type<<endl;
    cout<<endl;
}

void change(Car c){  // Pass by Value (Deep copy)
    c.price=850000;
    c.seats=6;
}

void changeByReference(Car& c){  // Pass by Reference (Shallow copy)
    c.price=850000;
    c.seats=6;
}

int main(){
    Car c1;
    c1.name="Maruti Swift";
    c1.price=700000;
    c1.seats=5;
    c1.type="Hatchback";
    
    cout<<"Before changing details: "<<endl;
    printDetail(c1);

    change(c1);
    
    cout<<"After changing details: "<<endl;
    printDetail(c1);
    
    cout<<"Before changing details: "<<endl;
    printDetail(c1);

    changeByReference(c1);
    
    cout<<"After changing details: "<<endl;
    printDetail(c1);

    // Car c2;
    // c2.name="Honda City";
    // c2.price=1500000;
    // c2.seats=5;
    // c2.type="Sedan";

    // Car c3;
    // c3.name="Toyoyta Fortuner";
    // c3.price=3600000;
    // c3.seats=8;
    // c3.type="SUV";

    // printDetail(c1);
    // printDetail(c2);
    // printDetail(c3);
}