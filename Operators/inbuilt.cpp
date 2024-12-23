#include<iostream>
#include<bitset>
using namespace std;

void decimalToOctal(int num) {
    cout << "Octal: " << oct << num << endl;
}

void decimalToHexadecimal(int num) {
    cout << "Hexadecimal: " << hex << num << endl;
}

int main(){
    bitset<3> binary(5);
    cout<<binary<<endl;
    decimalToOctal(8);
    decimalToHexadecimal(17);
    return 0;
}