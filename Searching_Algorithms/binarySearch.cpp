#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int> &v,int target){
    int low=0,high=v.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(v[mid]==target) return mid;
        else if(v[mid]<target) low=mid+1;
        else high=mid-1;
    }
    return -1;
}
int main(){
    vector<int> v={2,5,7,9,12,36,78};
    int target; cin>>target;
    int result=binarySearch(v,target);
    if(result==-1) cout<<"Element not Present";
    else cout<<"Element Present at the index "<<result;
    return 0;
}