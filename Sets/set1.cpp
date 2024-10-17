#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int main(){
    // set<int,greater<int>> st;
    set<int> st;

    st.insert(3);
    st.insert(2);
    st.insert(1);
    st.insert(4);
    st.insert(5);

    // cout<<st.size()<<endl;
    // st.insert(3);
    // cout<<st.size()<<endl;

    set<int>::iterator itr;
    for(itr=st.begin();itr!=st.end();itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;

    // st.erase(4);
    auto itr2=st.begin();
    advance(itr2,3);
    st.erase(itr2);

    for(auto iterator: st){
        cout<<iterator<<" ";
    }
    cout<<endl;

    st.insert(6);
    st.insert(7);
    st.insert(8);
    st.insert(9);

    for(auto iterator: st){
        cout<<iterator<<" ";
    }
    cout<<endl;

    auto start_itr=st.begin();
    start_itr++;

    auto end_itr=st.begin();
    advance(end_itr,3);

    st.erase(start_itr,end_itr);

    set<int>::iterator itr3;
    for(itr3=st.begin();itr3!=st.end();itr3++){
        cout<<*itr3<<" ";
    }cout<<endl;

    if(st.find(4)!=st.end()){
        cout<<"Present";
    }else{
        cout<<"Not Present";
    }

    return 0;
}