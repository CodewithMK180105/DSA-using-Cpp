// Remove all occurrences of 'a' from a string.

#include<iostream>
using namespace std;
void removeOccurences(string str, string result,int idx){
    if(idx==str.length()){
        cout<<result<<endl;
        return;
    }
    if(str[idx]!='a' && str[idx]!='A') result+=str[idx];
    removeOccurences(str,result,idx+1);
}
int main(){
    removeOccurences("Raghav Garg","",0);
    return 0;
}