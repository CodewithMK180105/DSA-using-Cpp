#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int> s1;
    s1.insert(0);
    s1.insert(41);
    s1.insert(2);
    s1.insert(3);


    for(auto value:s1){
        cout<<value<<" ";
    }
    cout<<endl;
    return 0;
}