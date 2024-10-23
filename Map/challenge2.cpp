// Can you make the strings equal

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
bool equalStrings(vector<string> v){
    unordered_map<char,int> charCount;
    for(int i = 0; i < v.size();i++){
        for(int j = 0; j < v[i].length();j++){
            charCount[v[i][j]]++;
        }
    }
    int n=v.size();
    for(int i = 0; i <charCount.size();i++){
        if(charCount[i]%n!=0){
            return false;
        }
    }
    return true;
}
int main(){
    vector<string> v={"collegeee","coll","collegge"};
    // vector<string> v={"wall","ah","wallah"};
    cout<<(equalStrings(v)?"Yes":"No")<<endl;
    return 0;
}