#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main(){
    map<string,int> call;
    call["John"] = 1234;
    call["Gane"] = 9876;
    call.insert(make_pair("Ram",4563));

    for(auto element: call){
        cout<<element.first<<"=>"<<element.second<<endl;
    }cout<<endl;

    call["Gane"] = 5845;  // The key value for the "Gane" will be updated.
    for(auto element: call){
        cout<<element.first<<"=>"<<element.second<<endl;
    }cout<<endl;

    return 0;
}