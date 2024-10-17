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

    void print(int runs){
        cout<<runs<<". Name: "<<this->name<<", runs: "<<this->runs<<", avg: "<<this->avg<<endl;
    }

    void matches(){
        cout<<this->name<<": "<<this->runs/this->avg<<endl;
    }
};
int main(){
    Cricketer rohit("Rohit Sharma",18000,53.7);
    Cricketer virat("Virat Kohli",25000,69.7);

    rohit.print(1);
    virat.print(2);

    rohit.matches();
    virat.matches();
}