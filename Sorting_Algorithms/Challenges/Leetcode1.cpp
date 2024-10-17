#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v1={1,2,2,1};
    vector<int> v2={3,3,3,4};
    int k; cin>>k;

    if(v1.size()!=v2.size()){
        cout<<"Error: Both the vectors must have the same number of the elements";
        return 0;
    }

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end(),greater<int>());

    bool flag=true;
    for(int i=0;i<v1.size();i++){
        if(v1[i]+v2[i]<k){
            flag=false;
            break;
        }
    }

    if(flag){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    
    return 0;
}