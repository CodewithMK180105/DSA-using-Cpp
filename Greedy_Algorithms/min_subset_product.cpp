#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;
int minProduct(vector<int> &arr){
    int n=arr.size();
    int cn=0,cz=0,cp=0,negProd=1,posProd=1;
    int largestNeg=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            cn++;
            negProd*=arr[i];
            largestNeg=max(largestNeg, arr[i]);
        }
        if(arr[i]==0) cz++;
        if(arr[i]>0){
            cp++;
            posProd*=arr[i];
        }
    }

    if(cn==0){ // No negative number present
        if(cz>0) return 0;
        else {
            auto it=min_element(arr.begin(), arr.end());
            return *it;
        }
    } else{
        if(cn%2==0){
            return (negProd/largestNeg)*posProd;
        } else{
            return negProd*posProd;
        }
    }
}
int main(){
    vector<int> v={-2, -3, 1, 4, -2, -5};
    cout<<minProduct(v);
    return 0;
}