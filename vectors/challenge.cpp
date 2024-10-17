#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v(6);
    for(int i=0;i<v.size();i++){
        cin>>v[i];
    }
    int oddSum=0;
    int evenSum=0;
    for(int i=0;i<v.size();i++){
        if(i%2==0) evenSum+=v[i];
        else oddSum+=v[i];
    }
    if(evenSum>oddSum) cout<<evenSum-oddSum;
    else cout<<oddSum-evenSum;
}