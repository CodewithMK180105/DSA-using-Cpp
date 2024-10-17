// Experimental Analysis
#include<iostream>
using namespace std;
int AP(int x,int y){
    int n=y-x+1;
    int a=x;
    return (n*(2*a+(n-1)))/2;
}
int sumWithLoop(int x,int y){
    int sum=0;
    for(int i=x;i<=y;i++) sum+=i;
    return sum;
}
int main(){
    int x,y;
    cin>>x>>y;
    cout<<sumWithLoop(x,y)<<endl;
    cout<<AP(x,y)<<endl;
    return 0;
}