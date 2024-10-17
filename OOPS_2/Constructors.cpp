#include<iostream>
using namespace std;

class Identity{
    public:
        int rno;
        string name;
        float gpa;

        Identity(){
            // This is a default constructor
        }

        Identity(int r, string n, float g){ //Parametrized constructor
            rno=r;
            name=n;
            gpa=g;
        }

        Identity(int r, string n){
            rno=r;
            name=n;
        }
};

int main(){

    Identity i1(92,"Manishkumar",9.1);
    cout<<i1.rno<<" "<<i1.name<<" "<<i1.gpa<<endl;

    Identity i2;
    i2.rno=76;
    i2.name="Raghav";
    i2.gpa=9.5;
    cout<<i2.rno<<" "<<i2.name<<" "<<i2.gpa<<endl;

    Identity i3(65,"Janya"); // 2 values passed through constructor
    i3.rno=81; // values can be over-ridden
    i3.gpa=8.5; // gpa provided normally
    cout<<i3.rno<<" "<<i3.name<<" "<<i3.gpa<<endl;

    Identity i4=i1; // Copy constructor (Deep copy)
    i4.gpa=9.3; // values can be over-ridden directly using assignment operator
    cout<<i4.rno<<" "<<i4.name<<" "<<i4.gpa<<endl;

    Identity i5(i2); // Copy constructor (Deep copy)
    i5.name="Jay"; // values can be over-ridden directly using assignment operator
    cout<<i5.rno<<" "<<i5.name<<" "<<i5.gpa<<endl;


    return 0;
}