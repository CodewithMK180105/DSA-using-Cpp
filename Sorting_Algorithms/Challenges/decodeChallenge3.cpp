// Given an array with N distinct elements, convert the given array to a form where all elements are in the range from 0 to N-1 inclusive. The order of the elementsis the same, i.e 0 is placed witht the smallest element, 1 is placed with the second smallest element, .... N-1 is placed for the largest element.

// Constraint: Solve it using time complexity of O(n*log(n))

// Hint: [use Hashmap]

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main(){
    vector<int> input={19,12,23,8,16};
    // vector<int> input={19,-12,-23,8,0};
    int n=input.size();
    unordered_map<int,int> mp;

    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;

    vector<int> inputSorted=input;

    sort(inputSorted.begin(),inputSorted.end());

    int count=0;
    for(int i=0;i<n;i++){
        mp.insert({inputSorted[i],count});
        count++;
    }

    vector<int> result;
    for(int i=0;i<n;i++){
        result.push_back(mp[input[i]]);
    }

    for(int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;

    return 0;
}