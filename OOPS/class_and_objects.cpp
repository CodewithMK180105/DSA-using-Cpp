#include<iostream>
using namespace std;

class Fruit{       // Creating a class
public:
    string name;
    string color;
};                 // Semicolon necessary

int main(){
    Fruit apple;   // Creating an Object
    apple.name="Apple";
    apple.color="Red";
    cout<<apple.name<<"-"<<apple.color<<endl;

    Fruit *mango =new Fruit();   // Creating an object using new Keyword
    mango->name="Mango";
    mango->color="Yellow";
    cout<<mango->name<<"-"<<mango->color;

    return 0;
}