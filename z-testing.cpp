#include<iostream>
using namespace std;
void subsets(string original, string ans, int i, int &n){
    if(i==n){
        cout<<ans<<endl;
        return;
    }
    
    subsets(original, ans, i+1, n);
    subsets(original, ans+original[i], i+1, n);
}
int main(){
    string str="abcd";
    int n=str.length();
    subsets(str, "", 0, n);
    return 0;
}