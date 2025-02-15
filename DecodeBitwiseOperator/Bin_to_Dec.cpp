#include<iostream>
using namespace std;
int binToDec(string binary){
    int n=binary.length();
    int result=0;
    for(int i=n-1;i>-1;i--){
        char ch=binary[i];
        int num=ch-'0';
        result+=num*(1<<(n-i-1));
    }
    return result;
}
int main(){
    cout<<binToDec("001011");
    return 0;
}