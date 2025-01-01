// Print the increasing-decreasing sequence.
// Input:  n=4
// Output: 1 2 3 4 3 2 1

#include<iostream>
using namespace std;
void printSequence(int x,int n){
    if(x>=n){
        cout<<n<<" ";
        return;
    }
    cout<<x<<" ";
    printSequence(x+1,n);
    cout<<x<<" ";
}
int main(){
    printSequence(1,4);
    return 0;
}