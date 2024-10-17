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

void change(Cricketer *c){
    // (*c).avg=88;
    c->avg=101;
}

int main(){
    Cricketer rohit("Rohit Sharma",18000,53.7);
    cout<<rohit.avg<<endl;
    change(&rohit);
    cout<<rohit.avg<<endl;


    // Cricketer *p=&rohit;
    // cout<<(*p).runs<<endl; // rohit.runs
    // cout<<rohit.avg<<endl;
    // (*p).avg+=10;
    // cout<<rohit.avg<<endl;

}