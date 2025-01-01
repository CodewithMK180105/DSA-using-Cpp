// Print the increasing-decreasing sequence.
// Input:  n=5
// Output: 5 4 3 2 1 2 3 4 5

#include<iostream>
using namespace std;
void printSequence(int n){
    if(n==1){
        cout<<n<<" ";
        return;
    }
    cout<<n<<" ";
    printSequence(n-1);
    cout<<n<<" ";
}
int main(){
    printSequence(5);
    return 0;
}

// 5 4 3 2 1 2 3 4 5