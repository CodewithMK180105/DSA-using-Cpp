#include<iostream>
using namespace std;
class Player{
public:
    int score;
    int health;
    string name; 
};
int main(){
    Player manishkumar;
    manishkumar.name="Manishkumar";
    manishkumar.health=20;
    manishkumar.score=100;
    cout<<manishkumar.name<<" ";
    cout<<manishkumar.health<<" ";
    cout<<manishkumar.score<<" ";

    cout<<endl;
    
    Player amit;
    amit.name="Amit";
    amit.health=18;
    amit.score=91;
    cout<<amit.name<<" ";
    cout<<amit.health<<" ";
    cout<<amit.score<<" ";
    return 0;
}