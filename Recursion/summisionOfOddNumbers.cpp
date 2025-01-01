// Write a program to calculate the sum of the odd numbers between a and b (both inclusive) using the recursion.
// a=2 and b=9 ===> sum=3+5+7+9=24

// #include<iostream>
// using namespace std;
// int summision(int a,int b){
//     if(a>b) return 0;
//     if(a%2!=0) return a+summision(a+1,b);
//     else return summision(a+1,b);
// }
// int main(){
//     cout<<summision(2,9);
//     return 0;
// }

// (2,9) => summision(3,9)
// (3,9) => 3+summision(4,9)
// (4,9) => summinsion(5,9)
// (5,9) => 5+summision(5,9)
// (6,9) => summision(7,9)
// (7,9) => 7+summision(8,9)
// (8,9) => summision(9,9)
// (9,9) => 9+summision(10,9)
// (10,9) => 0


// Approach-2

#include<iostream>
using namespace std;
int summision(int a,int b){
    if(a>b) return 0;
    return a+summision(a+2,b);
}
int main(){
    int a=2,b=9;
    if(a%2==0) a++;
    cout<<summision(a,b);
    return 0;
}

// (3,9) => 3+summision(5,9)
// (5,9) => 5+summision(7,9)
// (7,9) => 7+summision(9,9)
// (9,9) => 9+summision(11,9)
// (11,9) => 0