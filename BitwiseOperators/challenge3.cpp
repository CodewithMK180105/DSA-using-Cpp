// Count the number of set bits in an integer.

// Input: A single integer n.
// Output: Number of 1s in its binary representation.

#include<iostream>
#include<vector>
using namespace std;
int countOnes(int n) {
    int count=0;
    while(n){
        n=n&(n-1);
        count++;
    }
    return count;
}
int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<"Number of 1's are : "<<countOnes(n);
    return 0;
}

// Explanation of Brian Kernighan's Algorithm
// For any integer 𝑛, n&(n−1) clears the least significant set bit in n.