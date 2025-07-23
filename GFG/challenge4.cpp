#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> v={1, 2, 5, 10, 20, 50};
    sort(v.begin(), v.end());
    int k=3;

    int i=0,j=v.size()-1, cost=0;
    while(i<j){
        cost+=v[i]; 
        i++;
        j-=k;
    }
    cout<<cost;
    return 0;
}