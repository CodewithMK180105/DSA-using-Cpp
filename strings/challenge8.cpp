// Given a string consisting of lowercase English characters. Print the characters that is occuring the most number of the times.

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    // string str="raghavgarg";
    string str="leetcode";
    int n=str.length();
    vector<int> v(26,0);

    for(int i=0;i<n;i++){
        v[str[i]-'a']++;
    }

    int max=0;
    for(int i=0;i<26;i++){
        if(max<v[i]) max=v[i];
    }

    for(int i=0;i<26;i++){
        if(v[i]==max){
            cout<<(char)(i+'a')<<v[i]<<endl;
        }
    }
    return 0;
}