// https://www.geeksforgeeks.org/competitive-programming/space-optimization-using-bit-manipulations/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool checkbit(int arr[], int ele){
    int idx=(ele/32), rem=ele%32;
    int val=arr[idx];
    val=(val>>(31-rem))&1;
    if(val==0) return false;
    else return true;
}
void setbit(int arr[], int ele){
    int idx=(ele/32), rem=ele%32;
    arr[idx] |=(1<<(31-rem));
}
int main(){
    int a,b;
    cin>>a>>b;
    int range=b-a+1;
    int size=ceil((double)range/32);

    int* arr=new int[size](); // () --> denote that the array is initialized with all 0

    for(int i=a;i<=b;i++){
        if(i%2==0 || i%5==0){
            setbit(arr, i-a);
        }
    }

    cout<<"Numbers marked in bit array: ";
    for (int i=a;i<=b;i++) {
        if (checkbit(arr,i-a)) {
            cout<<i<<" ";
        }
    }
    cout<<endl;


    return 0;
}