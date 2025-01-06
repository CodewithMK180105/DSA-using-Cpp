#include<iostream>
using namespace std;
void generateParanthesis(string para, int n, int openingCount, int closingCount){
    if(para.length()==2*n){
        cout<<para<<endl;
        return;
    }
    if(closingCount>openingCount) return;
    
    if(openingCount<n) generateParanthesis(para+'(',n,openingCount+1,closingCount);
    generateParanthesis(para+')',n,openingCount,closingCount+1);
}
int main(){
    generateParanthesis("",1,0,0);
    return 0;
}