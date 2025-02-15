#include<iostream>
using namespace std;
class Gun{
    public:
        int ammo;
        int damage;
        int scope;
};
class Player{
    private:

        class Helmet {
            int hp;
            int level;

            public:
                void setHp(int hp){
                    this->hp=hp;
                }
                void setLevel(int level){
                    this->level=level;
                }
                int getHp(){
                    return hp;
                }
                int getLevel(){
                    return level;
                }
        };
        int health;
        int age;
        int score;
        bool isAlive;
        Gun gun;
        Helmet helmet;

    public:
        int getHealth(){
            return health;
        }
        int getScore(){
            return score;
        }
        int getAge(){
            return age;
        }
        int getIsAlive(){
            return isAlive;
        }
        Gun getGun(){
            return gun;
        }
        void setHealth(int health){
            this->health=health;
        }
        void setScore(int score){
            this->score=score;
        }
        void setAge(int age){
            this->age=age;
        }
        void setIsAlive(bool isAlive){
            this->isAlive=isAlive;
        }
        void setGun(Gun gun){
            this->gun=gun;
        }
        void setHelmet(int level){
            Helmet *helmet=new Helmet;
            helmet->setLevel(level);
            int health=0;
            if(level==1) health=25;
            else if(level==2) health=50;
            else if(level==3) health=100;
            else cout<<"Invalid level";

            helmet->setHp(health);
            this->helmet=*helmet;
        }
        Helmet getHelmet(){
            return helmet;
        }
};
int add(Player a, Player b){
    return a.getScore()+b.getScore();
}
Player compareScore(Player a, Player b){
    if(a.getScore()>b.getScore()){
        return a;
    } else return b;
}
int main(){
    Player aman;
    Gun akm;
    akm.ammo=100;
    akm.damage=50;
    akm.scope=2;
    aman.setAge(19);
    aman.setHealth(100);
    aman.setIsAlive(true);
    aman.setScore(100);
    aman.setGun(akm);
    aman.setHelmet(2);
        
    Player raghav;
    Gun awm;
    awm.ammo=15;
    awm.damage=150;
    awm.scope=8;
    raghav.setAge(22);
    raghav.setHealth(20);
    raghav.setIsAlive(true);
    raghav.setScore(12);
    raghav.setGun(awm);
    aman.setHelmet(3);

    Gun gun123=raghav.getGun();
    cout<<gun123.ammo<<" "<<gun123.damage<<" "<<gun123.scope<<endl;

    // cout<<add(raghav, aman)<<endl;

    // Player sanket=compareScore(raghav, aman);
    // cout<<sanket.getScore()<<endl;
    return 0;
}