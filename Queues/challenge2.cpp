// You are given an array of integers, there is a sliding window of size k which is moving from very left to the array from very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window which basically contains the max element in each row.

#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<int> max_window(vector<int> &arr,int k){
    deque<int> dq;
    vector<int> res;
    for(int i=0;i<k;i++){
        while(not dq.empty() && arr[dq.front()]<arr[i]){
            dq.pop_front();
        }
        dq.push_back(i);
    }
    res.push_back(arr[dq.front()]);
    
    for(int i=k;i<arr.size();i++){
        if(dq.front()==(i-k)){
            dq.pop_back();
        }
        while(not dq.empty() && arr[dq.front()]<arr[i]){
            dq.pop_front();
        }
        dq.push_back(i);
        res.push_back(arr[dq.front()]);
    }
    return res;
}

int main(){
    vector<int> dq;
    dq.push_back(1);
    dq.push_back(3);
    dq.push_back(-1);
    dq.push_back(-3);
    dq.push_back(5);
    dq.push_back(3);
    dq.push_back(6);
    dq.push_back(7);
    vector<int> res=max_window(dq,3);
    for(int i: res) cout<<i<<" ";
    return 0;
}