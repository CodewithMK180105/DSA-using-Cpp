#include<iostream>
using namespace std;
int main(){
    char vowels[5];
    for(char &element:vowels) cin>>element;
    for(char element:vowels) cout<<element<<" ";
    return 0;
}