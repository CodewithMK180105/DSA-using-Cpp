#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_multimap<string,int> fruitcount;

    fruitcount.insert({"apple", 6});
    fruitcount.insert({"banana", 9});
    fruitcount.insert({"apple", 3});

    for(auto pair: fruitcount){
        cout<<"Fruit: "<<pair.first<<"=> Count: "<<pair.second<<endl;
    }
    return 0;
}