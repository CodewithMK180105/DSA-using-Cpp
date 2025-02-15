#include<iostream>
using namespace std;
class Player{
public:
    string name; 
    int age;
    string role="Employee";
private:
    int salary;
};
int main(){
    Player manishkumar;
    manishkumar.name="Manishkumar";
    manishkumar.age=20;
    manishkumar.role="Software Developer";
    cout<<manishkumar.name<<" ";
    cout<<manishkumar.age<<" ";
    cout<<manishkumar.role<<" ";

    cout<<endl;
    
    Player amit;
    amit.name="Amit";
    amit.age=21;
    cout<<amit.name<<" ";
    cout<<amit.age<<" ";
    cout<<amit.role<<" ";
    return 0;
}