#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
bool isPossible(vector<int> &arr,int N,int M,int maxAllowedArea){
    int painters=1,currTime=0;
    for(int i=0;i<N;i++){
        if(currTime+arr[i]>maxAllowedArea){
            painters++;
            currTime=arr[i];
        }else{
            currTime+=arr[i];
        }
    }
    if(painters>M){
        return false;
    }else{
        return true;
    }
}
int getMinTime(vector<int> &arr,int N,int M){
    int st=0,end=0;
    for(int i=0;i<arr.size();i++){
        end+=arr[i];
    }
    int ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isPossible(arr,N,M,mid)){
            ans=mid;
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> arr={40,30,10,20};
    int N=arr.size();
    int M=2;
    cout<<getMinTime(arr,N,M);
    return 0;
}