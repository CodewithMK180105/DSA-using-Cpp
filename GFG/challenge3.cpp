// https://www.geeksforgeeks.org/dsa/find-maximum-height-pyramid-from-the-given-array-of-objects/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> v={10, 20, 30, 50, 60, 70};
    int n=v.size();
    // sort(v.begin(), v.end());
    int res=0, i=1;

    while(true){
        int summission=i*(i+1)/2;
        if(summission>n) break;
        i++; res++;
    }
    cout<<res;
    return 0;
}