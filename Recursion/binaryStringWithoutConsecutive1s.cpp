// Generate all binary strings of length n, without consecutive 1's.

#include<iostream>
using namespace std;
void printBinaryStrings(string binary, int count){
    if(count==binary.length()){
        cout<<binary<<endl;
        return;
    }
    printBinaryStrings(binary+"0",count);
    if(binary.empty() || binary.back()=='0') printBinaryStrings(binary+"1",count);
}
int main(){
    printBinaryStrings("",3);
    return 0;
}