#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main(){

    vector<int> v1;
    vector<int> v2;

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v1.push_back(temp);
    }
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        v2.push_back(temp);
    }

    set<int> s1;
    for(auto ele: v1){
        s1.insert(ele);
    }

    int ansSum=0;

    for(auto ele: v2){
        if(s1.find(ele)!=s1.end()){
            ansSum+=ele;
        }
    }

    cout<<"Sum of the common elements is "<<ansSum;

    return 0;
}
