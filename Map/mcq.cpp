// what will be the output of the below code.

#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main(){
    map<int, int> call;
    call.insert({1,10});
    call.insert({1,20});   // This is an insert Function it will not update the key value of 1
    call.insert({3,30});
    call[4]=40;

    for(auto i: call){
        cout << i.first << " " << i.second <<endl;
    }

    return 0;
}