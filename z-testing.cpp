#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
    int n=height.size();
    vector<int> pge(n,-1);
    vector<int> nge(n,-1);
    
    for(int i=1;i<n;i++){
        pge[i]=max(pge[i-1],height[i-1]);
        nge[n-i-1]=max(nge[n-i],height[n-i]);
    } 
    for(int i=0;i<n;i++){
        cout<<pge[i]<<" ";
    }   
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<nge[i]<<" ";
    }   
    return 0;
}