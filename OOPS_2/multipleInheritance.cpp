#include<iostream>
using namespace std;
class Cricketer{
public:
    int runs;
    int wickets;
    float avg;
};
class Engineer{
public:
    int experience;
    string domain;
};
class Phodu: public Engineer, Cricketer{
    string name;
    int age;
    string hobby;
};
int main(){

    return 0;
}