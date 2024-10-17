// It is a function which is called when an object is deleted
// cannot pass any parameter
// Name:- ~(class_Name)

#include<iostream>
using namespace std;

class Rectangle{
public:
    int l;
    int b;

    Rectangle(){ // Default Constructor
        l=0;
        b=0;
    }

    Rectangle(int x, int y){ // parametrized contructor- args passed
        l=x;
        b=y;
    }

    Rectangle(Rectangle& r){ // Initialize an object by another existing one
        l=r.l;
        b=r.b;
    }

    ~Rectangle(){
        cout<<"Destructor is called"<<endl;
    }

};

int main(){
    Rectangle *r1=new Rectangle();
    cout << "Default Constructor: " << r1->l << " " << r1->b << endl;
    delete r1;

    Rectangle r2(3,4);
    cout << "Parametrized Constructor: " << r2.l << " " << r2.b << endl;

    Rectangle r3=r2;
    cout << "Copy Constructor: " << r3.l << " " << r3.b << endl;

    return 0;
}