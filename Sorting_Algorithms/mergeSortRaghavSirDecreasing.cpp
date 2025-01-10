#include <iostream>
using namespace std;
void merge(int a[], int n1, int b[], int n2, int res[]){
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(a[i]>b[j]){
            res[k]=a[i];
            i++;
        } else{
            res[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        res[k]=a[i];
        i++;
        k++;
    }
    while(j<n2){
        res[k]=b[j];
        j++;
        k++;
    }
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

    // Merge
    merge(a,n1,b,n2,arr);

    delete a;
    delete b;
}
int main()
{
    int arr[]={5,1,3,0,4,6,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergeSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}