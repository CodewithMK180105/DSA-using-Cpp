// Binding of methods and variables together into a single unit(class) is Encapsulation
// Data is accessible only from the class methods
// It also leads to the data abstraction (hiding class Abstract datatype)


// Abstraction
// Enables us to display only essential information while hiding implementation details
// eg: pow(x,y);

#include<iostream>
using namespace std;

class ABC{
    int x;
    public:
    void set(int y){
        x=y;
    }
    int get(){
        return x;
    }
};

int main(){
    ABC abc;
    abc.set(9);
    cout<<abc.get();
    return 0;
}