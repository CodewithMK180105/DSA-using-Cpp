// Two elements of an array a. a[i] and a[j] form an inversion if a[i]>a[j] and i<j. Given an array of integers. Find the inversion count in an array.

// eg: 5 1 8 2 3
// 
//      (5,1)
//      (5,2)
//      (5,3)
//      (8,2)
//      (8,3)
// 
// return 5

// Approach-1 : Brute Force O(n^2)

// #include<iostream>
// #include<vector>
// using namespace std;
// int BruteForce(vector<int> v){
//     int n=v.size();
//     int count=0;
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(v[i]>v[j]) count++;
//         }
//     }
//     return count    ;
// }
// int main(){
//     vector<int> v={5,1,3,0,4,9,6};
//     cout<<BruteForce(v);
//     return 0;
// }


// Approach-2 : Merge Sort O(n*(log(n)))

#include <iostream>
using namespace std;
int globalCount=0;
int inversionCount(int a[], int n1, int b[], int n2){
    int localCount=0;
    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        if(a[i]>b[j]){
            localCount+=n1-i;
            j++;
        }
        else i++;
    }
    return localCount;
}
void merge(int a[], int n1, int b[], int n2, int res[]){
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]) res[k++]=a[i++];
        else res[k++]=b[j++];
    }
    while(i<n1) res[k++]=a[i++];
    while(j<n2) res[k++]=b[j++];
}
void mergeSort(int arr[],int n){
    if(n==1) return;
    // Divide
    int n1=n/2, n2=n-n/2;
    int a[n1],b[n2];
    for(int i=0;i<n1;i++) a[i]=arr[i];
    for(int i=0;i<n2;i++) b[i]=arr[i+n1];

    // magic (Recursion)
    mergeSort(a,n1);
    mergeSort(b,n2);

    // Count the inversions
    globalCount+=inversionCount(a,n1,b,n2);

    // Merge
    merge(a,n1,b,n2,arr);

    delete a;
    delete b;
}
int main()
{
    int arr[]={5,1,3,0,4,2,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergeSort(arr,n);
    cout<<globalCount;
    return 0;
}