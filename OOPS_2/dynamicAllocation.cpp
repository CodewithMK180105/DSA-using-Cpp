#include<iostream>
using namespace std;

class Cricketer{
    public:
    string name;
    int runs;
    float avg;

    Cricketer(string name, int runs,float avg){
        this->name=name;
        this->runs=runs;
        this->avg=avg;
    }
};

int main(){
    Cricketer* cr = new Cricketer("Gautam Gambhir",50000,75.6);
    cout<<cr->name<<endl;
    cout<<cr->runs<<endl;
    cout<<cr->avg<<endl;
    return 0;
}