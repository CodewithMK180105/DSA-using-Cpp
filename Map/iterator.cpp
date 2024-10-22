#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main(){
    map<string,int> call;
    call["John"] = 1234;
    call["Gane"] = 9876;
    call.insert(make_pair("Ram",4563));
    call.insert({"Mary",5555});

    // Traverse in the straight order
    map<string,int>::iterator itr;
    for(itr=call.begin(); itr != call.end();itr++){
        cout<<itr->first<<"=>"<<itr->second<<endl;
    }

    // Traverse in the reverse order.
    map<string,int>::reverse_iterator itr2;
    for(itr2=call.rbegin(); itr2 != call.rend();itr2++){
        cout<<itr2->first<<"=>"<<itr2->second<<endl;
    }

    return 0;
}