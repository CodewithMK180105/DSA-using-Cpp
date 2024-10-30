// Input a string and return the number of times the neighboring characters are different from the each other/\.

#include<iostream>
#include<string>
using namespace std;

int countDiffNeighbors(string str){
    int n=str.length();
    if(n==1) return 0;
    if(n==2 && str[0]!=str[1]) return 1;
    int count = 0;
    for(int i=0;i<n;i++){
        if(i==0 && str[i]!=str[i+1]){
            count++;
            continue;
        }
        if(i==n-1 && str[i]!=str[i-1]){
            count++;
            continue;
        }
        if(str[i]!=str[i-1] && str[i]!=str[i+1]){
            count++;
        }
    }
    return count;
}
int main(){
    // string str="abbcdeffghh";
    string str="ab";
    cout<<countDiffNeighbors(str);
    return 0;
}