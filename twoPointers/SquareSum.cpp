#include<iostream>
#include<cmath>
using namespace std;

bool judgeSquareSum(int c) {
    long long left=0,right=sqrt(c);
    cout<<right<<endl;
    while(left<=right){
        if((left*left + right*right)==c){
            return true;
        } else if((left*left + right*right)>c){
            right--;
        } else{
            left++;
        }
    }
    return false;
}

int main(){
    cout<<judgeSquareSum(64);
}