#include<iostream>
using namespace std;
class Player{
    private:
        int health;
        int score;

    public:
        void setHealth(int h){
            health=h;
        }
        void setScore(int s){
            score=s;
        }
        int getHealth(){
            return health;
        }
        int getScore(){
            return score;
        }
};
int main(){
    Player harsh;
    harsh.setHealth(11);
    cout<<harsh.getHealth()<<endl;
    
    harsh.setScore(115);
    cout<<harsh.getScore()<<endl;
    return 0;
}