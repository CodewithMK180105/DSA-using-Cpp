#include<iostream>
#include<vector>
using namespace std;
void findQuery(vector<int> v){
    int q; cin>>q;
    while(q--){
        int hr,lr;
        cout<<"Enter the lower and the higher range : ";
        cin>>lr>>hr;
        int ans=v[hr]-v[lr-1];
        cout<<ans<<endl;
    } 
}
//   1 2 3 4 5 6 7 8 9
// 0 1 2 3 4 5 6 7 8 9
int main(){
    int n; cin>>n;
    vector<int> v(n+1,0); // size of vector=n+1 and the elements are initialized to as 0
    for(int i=1;i<n+1;i++){
        cin>>v[i];
    }
    for(int i=1;i<n+1;i++) v[i]+=v[i-1];
    cout<<"The Prefix Sum Array is : ";
    for(int i=1;i<n+1;i++) cout<<v[i]<<" ";
    cout<<endl;
    findQuery(v);
        return 0;
    }