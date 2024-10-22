// given a vector of integers of size n, You have return the sum of repetitive elements ie the elements that appear more than 1 times.

#include<iostream>
#include<vector>
#include<map>
using namespace std;

int repeatedSum(vector<int> arr){
    int sum=0;
    int n=arr.size();
    map<int,int> map_name;
    for(int i=0;i<n;i++){
        map_name[arr[i]]++;
    }

    for(auto ele: map_name){
        if(ele.second>1) sum+=ele.first;
    }
    return sum;
}

int main(){
    vector<int> arr={1,2,3,2,1,4,5,6,2,3};
    cout<<repeatedSum(arr);
    return 0;
}


// 1,2,3,2,1,4,5,6,2,3