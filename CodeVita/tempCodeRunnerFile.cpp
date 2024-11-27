#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int simulateGame(int start, vector<int>& diceRolls, unordered_map<int,int>& environment){
    int position=start;
    for(int roll: diceRolls){
        position+=roll;
        if(position>100) return 100;
        if(environment.find(position)!=environment.end()) position=environment[position];
    }
    return position;
}

string findFaultySwitch(int N,vector<pair<int,int>>& snakeLadder,vector<int>& diceRolls,int finalPosition){
    unordered_map<int,int> environment;
    for(auto chance: snakeLadder) environment[chance.first]=chance.second;
    int positionWithoutSwitch=simulateGame(1,diceRolls,environment);

    if(positionWithoutSwitch==finalPosition) return "Not affected";

    for(auto chance: snakeLadder){
        unordered_map<int,int> modifiedBoard=environment;
        modifiedBoard.erase(chance.first);
      	modifiedBoard[chance.second]=chance.first;
        int newPosition=simulateGame(1,diceRolls,modifiedBoard);
        if(newPosition==finalPosition){
            string switchType=(chance.first<chance.second)? "Snake":"Ladder";
            return switchType+" "+to_string(chance.second)+" "+to_string(chance.first);
        }
    }
  return "Not reachable";
}
int main(){
    int N;
    cin>>N;
    vector<pair<int,int>> snakeLadder(N);
    for(int i=0;i<N;i++){
        int beg,stop;
        cin>>beg>>stop;
        snakeLadder[i]={beg,stop};
    }

    int diceRollCount;
    cin>>diceRollCount;
    vector<int> diceRolls(diceRollCount);
    for(int i=0;i<diceRollCount;i++) cin>>diceRolls[i];

    int finalPosition;
    cin>>finalPosition;

    cout<<findFaultySwitch(N,snakeLadder,diceRolls,finalPosition);
    return 0;
}