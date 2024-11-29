#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> v,int target,int left,int right){
    if(left>right) return -1;
    int mid=left+(right-left)/2;
    if(v[mid]==target){
        return mid;
    } else if(v[mid]<target){
        return binarySearch(v,target,mid+1,right);
    } else{
        return binarySearch(v,target,left,mid-1);
    }
}
int main(){
    vector<int> v={2,5,8,16,32,49,77};
    int target=40;
    int n=v.size();
    cout<<binarySearch(v,target,0,n-1);
    return 0;
}

// Time Complexity: O(log n)
// Space Complexity: O(log n)