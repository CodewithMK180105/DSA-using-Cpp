// Find the only non-repeating element in an array where every other element repeats twice.

// Input: An array of integers.
// Output: Return the unique number.
// Hint: Use XOR.

#include<iostream>
#include<bitset>
#include<vector>
using namespace std;
int singleNumber(vector<int>& nums) {
    int result=0;
    for(int i=0;i<nums.size();i++){
        result=result^nums[i];
    }
    return result;
}
int main(){
    vector<int> v={5,6,9,4,9,6,4};
    cout<<singleNumber(v);
    return 0;
}

// Approach:
// 1. a^0=a
// 2. a^a=0