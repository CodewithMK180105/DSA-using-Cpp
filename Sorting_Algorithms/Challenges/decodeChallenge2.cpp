// Given an array with N distinct elements, convert the given array to a form where all elements are in the range from 0 to N-1 inclusive. The order of the elementsis the same, i.e 0 is placed witht the smallest element, 1 is placed with the second smallest element, .... N-1 is placed for the largest element.

// Note: Input aarray contains only the positive numbers.

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int  main(){
    vector<int> input={19,12,23,8,16};
    int n=input.size();
    int x=0;

    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        int min=INT_MAX;
        int mindx=-1;
        for(int j=0;j<n;j++){
            if(input[j]>0 && min>input[j]){
                min=input[j];
                mindx=j;
            }
        }
        input[mindx]=x;
        x--;
    }

    for(int i=0;i<n;i++){
        input[i]*=-1;
        cout<<input[i]<<" ";
    }
    cout<<endl;

    return 0;
}

// Time Complexity: O(n2)
// Space Complexity: O(1)