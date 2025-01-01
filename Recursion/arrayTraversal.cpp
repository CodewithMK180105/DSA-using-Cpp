#include<iostream>
using namespace std;
void printArrayElements(int i, int n,int nums[]){
    if(i<n){
        cout<<nums[i]<<" ";
    }
    printArrayElements(i+1,n,nums);
}
int main(){
    int nums[]={5,7,1,3,6};
    printArrayElements(0,5,nums);
    return 0;
}