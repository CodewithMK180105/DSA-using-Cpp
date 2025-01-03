// Check whether a string is a palindrome or not? using recursion.

#include<iostream>
using namespace std;
bool isPalindrome(string str, int i, int j){
    if(i==j) return true;
    if(str[i]!=str[j]) return false;
    return isPalindrome(str,i+1,j-1);
}
int main(){
    string str="racecar";
    int n=str.length();
    cout<<isPalindrome(str,0,n-1);
    return 0;
}