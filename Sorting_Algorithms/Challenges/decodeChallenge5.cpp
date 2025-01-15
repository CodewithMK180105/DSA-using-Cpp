// Given an array where all of it's elements are sorted in increasing order except two swapped elements, sort it in linear time. Assume there ar no duplicates in the array.

// input: [3,8,6,7,5,9,10]
// output: [3,5,6,7,8,9,10]

#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> input={3, 11, 6, 7, 8, 9, 10, 4};
    int n=input.size();

    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    } cout<<endl;

    int firstPos=-1;
    int secondPos=-1;
    for(int i=0;i<n-1;i++){
        if(input[i]>input[i+1]){
            if(firstPos==-1) firstPos=i;
            else secondPos=i+1;
        }
    }
    swap(input[firstPos],input[secondPos]);
    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
    return 0;
}


// [3,11,6,7,8,9,10,4]