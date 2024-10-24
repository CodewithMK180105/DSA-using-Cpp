// Given an array of integer length n and a target, return a pair whose sum is equal to the target, If no such pair return -1.

#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> result(vector<int> v,int target){

    unordered_map<int, int> map;
    int n = v.size();

    vector<int> result(2,-1);

    for(int i = 0; i < n; i++){
        int diff=target-v[i];
        if(map.find(diff)!=map.end()){
            result[0]=map[diff];
            result[1]=i;
        }
        else{
            map[v[i]]=i;
        }
    }
    return result;
}

int main(){
    vector<int> v = {9, 10, 2, 3, 5};
    int target = 15;
    vector<int> res=result(v,target);
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}