#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b){
    return a[1]<b[1];
}
int main(){
    vector<vector<int>> jobs={{1,2}, {3,4}, {0,6}, {5,7}, {8,9}, {5,9}};
    int n=jobs.size();
    sort(jobs.begin(), jobs.end(), cmp);
    int overlapping=0;
    int lastTime=jobs[0][1];
    for(int i=1;i<n;i++){
        if(lastTime>jobs[i][0]){
            overlapping++;
        } else {
            lastTime=jobs[i][1];
        }
    }
    cout<<n-overlapping<<endl;
    return 0;
}