#include<iostream>
using namespace std;
int main(){
    int x=99;
    int &y=x;
    y=8;
    cout<<x<<" "<<y;
    return 0;
}

// #include<iostream>
// using namespace std;

// void swap(int &a,int &b){
//     int temp=a;
//     a=b;
//     b=temp;
// }

// int main(){
//     int x=4,y=9;
//     swap(x,y);
//     cout<<x<<" "<<y;
//     return 0;
// }