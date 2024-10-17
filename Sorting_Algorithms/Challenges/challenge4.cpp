// Given two sorted arrays write a program to merge them in a sorted manner.
// Input:- num1[]={5,8,10} and num2[]={2,7,8}
// Output:- soln[]={2,5,7,8,8,10}

#include<iostream>
using namespace std;
int main(){
    int num1[]={5,8,10};
    int n1=sizeof(num1)/sizeof(num1[0]);
    int num2[]={2,7,8};
    int n2=sizeof(num2)/sizeof(num2[0]);
    int soln[n1+n2];
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(num1[i]<num2[j]){
            soln[k++]=num1[i++];
        }
        else{
            soln[k++]=num2[j++];
        }
    }
    while(i<n1){
        soln[k++]=num1[i++];
    }
    while(j<n2){
        soln[k++]=num2[j++];
    }
    for(int k=0;k<n1+n2;k++) cout<<soln[k]<<" ";
    return 0;
}