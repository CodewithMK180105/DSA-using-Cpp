// Check if a number is a power of two.

// Input: A single integer n.
// Output: Return True if it is a power of two, otherwise False.

#include<iostream>
using namespace std;
bool isPowerOfTwo(int n) {
    if(n<=0) return false;
    if(n==1) return true;

    if((n&(n-1))==0){
        return true;
    } else {
        return false;
    }
}    
int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    if(isPowerOfTwo(n)){
        cout<<n<<" is a power of 2";
    } else{
        cout<<n<<" is not a power of 2";
    }
    return 0;
}