// Find the square root of a non-negative number x, Round it of to the nearest floor index value
// input: 4 , output :2
// input: 11 , output :3

#include<iostream>
#include<vector>
using namespace std;
int complexitySquareRootApproach(int x){
    int ans;
    for(int i=1;i<=x;i++){
        if(i*i<=x) ans=i;
        else break;
    }
    return ans;
}
int complexityLogApproach(int x){
    int low=0,high=x,ans=1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(mid*mid<=x){
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return ans;
}
int main(){
    int x; cin>>x;
    cout<<complexitySquareRootApproach(x)<<" ";
    cout<<complexityLogApproach(x);
    return 0;
}