#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v={7,1,2,5,8,4,9,3,6};
    int k=3;
    int i=0,j=0;
    int sum=0;
    for(j=0;j<k;j++){
        sum+=v[j];
    }

    while(j<v.size()){
        sum=max(sum, sum+v[j]-v[i]);
        i++, j++;
    }

    cout<<sum;
    return 0;
}