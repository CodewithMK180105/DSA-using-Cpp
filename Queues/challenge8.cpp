// First -ve integer in each window of size k.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    vector<int> v={0,-1,-2,3,4,-5,6,4,7,-8};
    int n=v.size();
    int k=3;
    vector<int> ans(n+k-1,0);
    queue<int> q;

    for(int i=0;i<n;i++){
        if(v[i]<0) q.push(i);
    }

    for(int i=0;i<n-k+1;i++){
        while(q.size()>0 && i>q.front()) q.pop();
        if(q.size()==0) break;
        if(q.front()<=i+k-1) ans[i]=v[q.front()];
    }

    for(int i=0;i<n-k+1;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}