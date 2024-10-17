#include<iostream>
#include<set>
using namespace std;
int main(){
    int n,p,q;
    cin>>n>>p>>q;
    set<int> s;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            int correct=i;
            int incorrect=j;
            int unattended=n-i-j;
            if(unattended>=0){
                int sum=correct*p+incorrect*q;
                s.insert(sum);
            }else{
                break;
            }
        }
    }
    for(auto value:s){
        cout<<value<<" ";
    }
    cout<<endl;
    cout<<s.size()<<endl;
    return 0;
}