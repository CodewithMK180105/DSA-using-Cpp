#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
void bucketSort(float arr[],int n){

    // step-1
    vector<vector<float>> bucket(n,vector<float>());
    float max_ele=INT_MIN;
    float min_ele=INT_MAX;
    for(int i=0;i<n;i++){
        max_ele=max(max_ele,arr[i]);
        min_ele=min(min_ele,arr[i]);
    }
    float range=(max_ele-min_ele)/n;

    // step-2
    for(int i=0;i<n;i++){
        int index=(arr[i]-min_ele)/range;
        float diff=(arr[i]-min_ele)/range-index;
        if(diff==0 && arr[i]!=min_ele) bucket[index-1].push_back(arr[i]);
        else bucket[index].push_back(arr[i]);
    }

    // step-3
    for(int i=0;i<n;i++){
        if(!bucket[i].empty()) sort(bucket[i].begin(),bucket[i].end());
    }

    // step-4
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<bucket[i].size();j++){
            arr[k++]=bucket[i][j];
        }
    }
}
int main(){
    float arr[]={6.13,8.45,0.12,1.89,4.75,2.63,7.85,10.39};
    int n=sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}