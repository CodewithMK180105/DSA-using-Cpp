// Generate all binary strings of length n.

#include<iostream>
using namespace std;
void printBinaryStrings(string binary, int count){
    if(count==binary.length()){
        cout<<binary<<endl;
        return;
    }
    printBinaryStrings(binary+"0",count);
    printBinaryStrings(binary+"1",count);
}
int main(){
    printBinaryStrings("",4);
    return 0;
}