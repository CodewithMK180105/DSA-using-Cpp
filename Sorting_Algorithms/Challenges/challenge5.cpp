// sort a string in decreasing orderof values associated after removal of the valuessmaller then X.

#include<iostream>
#include<string>
using namespace std;
int main(){
    string s="AZYZXBDJKX";
    string str="";
    for(char ch: s){
        if(ch>'W'){
            str+=ch;
        }
    }
    cout<<str<<endl;
    int n=str.length();
    for(int i=0;i<n-1;i++){
        bool flag=true;
        for(int j=0;j<n-1-i;j++){
            if(str[j]<str[j+1]){
                flag=false;
                swap(str[j],str[j+1]);
            }
        }
        if(flag) break;
    }
    cout<<str<<endl;
    return 0;
}