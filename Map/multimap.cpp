#include<iostream>
#include<map>
using namespace std;
int main(){
    multimap<string,int> directory;

    directory.insert({"urvi",8816}),
    directory.insert({"John", 1234});
    directory.insert({"John", 8796});
    directory.insert({"Sanjiv",8723});

    // directory["John"] = 5555; => No such [] method for multimap

    for(auto pair: directory){
        cout<<pair.first<<"-"<<pair.second<<endl;
    }

    return 0;
}