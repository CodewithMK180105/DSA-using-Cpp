// It is an inbuilt doubly linkedlist in C++ with some inbuilt functions

// list.begin(): iterator for the first element
// list.end(): iterator for the position after the last element
// list.rbegin(): iterator for the first element in the reverse order
// list.rend(): iterator for the position after last element in the reverse order
// advance(itr,n): advance the itr by n places

#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> l1={1,2,3,4};
    auto itr=l1.begin();
    // cout<<*itr<<endl;

    // advance(itr,2);
    // cout<<*itr<<endl;


    // using range based loop
    for(auto num:l1){
        cout<<num<<" ";
    } cout<<endl;

    // using iterators
    for(auto itr=l1.begin();itr!=l1.end();itr++){
        cout<<*itr<<" ";
    } cout<<endl;

    // Reverse Traversal
    for(auto itr=l1.rbegin();itr!=l1.rend();itr++){
        cout<<*itr<<" ";
    } cout<<endl;

    return 0;
}