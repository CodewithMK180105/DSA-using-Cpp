#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> l1={1,2,3,4,5};

    for(auto it=l1.begin();it!=l1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    l1.push_front(0);
    l1.push_back(6);

    for(auto it=l1.begin();it!=l1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    l1.pop_back();
    l1.pop_front();

    for(auto it=l1.begin();it!=l1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}