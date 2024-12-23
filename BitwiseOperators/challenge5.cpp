// Find the missing number in an array of size n containing numbers from 0 to n.

// Here we have 2 approaches to solve the question.
// 1. int total_sum=n*(n+1)/2;
// 2. Using Bitwise is operator.

#include<iostream>
#include<vector>
using namespace std;
int missingNumber(vector<int>& nums) {
    int n=nums.size();
    int total_sum=n*(n+1)/2;

    for(int i=0;i<n;i++){
        total_sum-=nums[i];
    }

    return total_sum;
}
int missingNumberBitOperator(vector<int>& nums) {
    int n=nums.size();
    int actual=0;
    int withMissing=0;
    for(int i=0;i<=n;i++){
        actual=(actual^i);
        if(i!=n){
            withMissing=(withMissing^nums[i]);
        }
    }
    return (actual^withMissing);
}
int main(){
    vector<int> v={9,6,4,2,3,5,7,0,1};
    cout<<"Using n*(n+1) : "<<missingNumber(v)<<endl;
    cout<<"Using XOR operator : "<<missingNumberBitOperator(v)<<endl;
    return 0;
}

// [0,1]
// i=0 ===> actual=0^0=0
//          withMissing=0^0=0

// i=1 ===> actual=0^1=1
//          withMissing=0^1=1

// i=2 ===> actual=1^2=(01)^(10)=11

// output: actual^withMissing=11^01=10