#include<iostream>
using namespace std;
string decToBin(int num){
    string result="";
    while(num>0){
        if(num%2==0){
            result="0"+result;
        }
        else{
            result="1"+result;
        }
        num/=2;
    }
    return result;
}
int main(){
    cout<<decToBin(13);
    return 0;
}