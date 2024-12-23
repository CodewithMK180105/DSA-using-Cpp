// Given Q queries, check if the given number is present in the array or not
// Note: value of all the elements in the array is less the 10 to the power 5

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    const int N=1e5+10;
    vector<int> freq(N,0);
    for(int i=0;i<n;i++) freq[v[i]]++;

    cout<<"Enter the no. of queries : ";
    int q; cin>>q;
    while(q--){
        int queryElement; cin>>queryElement;
        cout<<freq[queryElement]<<endl;
    }
    return 0;
}