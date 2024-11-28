// Given an array, arr[] containing 'n' integers, the the task is to find an integer (say k) such that after replacing the each and the every index of the array by |a[i]-k| where (i belongs to [1,n]) results in the sorted array. If no such of the integer exists that satisfies the above condition then return -1.

#include<iostream>
#include<climits>
#include<algorithm>
#include <cmath>
using namespace std;

int main(){
    int arr[]={5,3,10};
    int n=sizeof(arr)/sizeof(arr[0]);

    float kmin=(float)INT_MIN;
    float kmax=(float)INT_MAX;
    bool flag=true;

    for(int i=0;i<n-1;i++){
        if(arr[i]>=arr[i+1]){
            kmin=max(kmin,((arr[i]+arr[i+1])/2.0f));
        } else{
            kmax=min(kmax,((arr[i]+arr[i+1])/2.0f));
        }
        if(kmin>kmax){
            flag=false;
            break;
        }
    }



    if(!flag){
        cout<<-1;
    }else if(kmin==kmax){
        if(kmin-(int)kmin==0){
            cout<<"There is only one value of the k: "<<kmin;
        } else {
            cout<< -1;
        }
    } else{
        if(kmin-(int)kmin>0){
            kmin=(int)kmin+1;
        }
        cout<<"The range for values of the k is ["<<kmin<<","<<(int)kmax<<"]";
    }
    return 0;
}

// int arr[]={5,2,10};
// 2 1 7 => 3  ---> wrong
// 1 2 6 => 4  ---> correct
// 0 3 5 => 5  ---> correct
// 1 4 4 => 6  ---> correct
// 2 5 3 => 7  ---> wrong

// int arr[]={5,3,10,3};
// 1 3 4 3 => 6  ---> wrong
// 2 4 3 4 => 7  ---> wrong