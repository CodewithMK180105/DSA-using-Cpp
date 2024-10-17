// list.insert(itr,value):- insert value before the position of itr
// list.insert(itr,count,value):- insert value before the position of itr count no. of times
// list.iterator(itr,str_itr,end_itr):- insert value from str_itr(included) to end_itr(excluded) before itr

#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> l1={1,2,3,4};
    auto itr=l1.begin();

    // Insert 8 at 2nd position
    // advance(itr,2);
    // l1.insert(itr,8);

    // Insert 9, 4 times starting from 3rd position
    // advance(itr,3);
    // l1.insert(itr,4,9);

    auto l=l1.begin();
    auto r=l1.begin();
    advance(r,2); // r is now at the 3rd element
    l1.insert(itr,l,r);


    for(auto it=l1.begin();it!=l1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}