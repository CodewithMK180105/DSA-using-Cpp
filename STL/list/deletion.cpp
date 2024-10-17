// list.erase(itr):- delete's the element pointed by the itr
// list.erase(str_itr,end_itr):- delete the element's from str_itr(included) to end_itr(excluded)

#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> l1={1,2,3,4,5};
    auto itr =l1.begin();

    // Delete 3 from l1
    // advance(itr,2);
    // l1.erase(itr);

    auto l=l1.begin();
    auto r=l1.begin();
    advance(r,3); // r is now at the 3rd element
    l1.erase(l,r);


    for(auto it=l1.begin();it!=l1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}