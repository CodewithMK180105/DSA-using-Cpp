// Sort the numbers in a given array/vector such that the even number occupies
// the leftmost position and the odd number occupies the rightmost position

#include<iostream>
#include<vector>
using namespace std;
int swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int ele; cin>>ele;
        v.push_back(ele);
    }
    int i=0,j=n-1;
    while(i<j){
        if(v[i]%2==1 && v[j]%2==0){
            swap(&v[i++],&v[j--]);
        }
        if(v[i]%2==0) i++;
        if(v[j]%2==1) j--;
    }
    for(int i=0;i<n;i++) cout<<v[i]<<" ";
    return 0;
}