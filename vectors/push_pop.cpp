// Vectors are the dynamic arrays which can be resized whenever there is an insertion or deletion in the vector
// Vectors and arrays both has contiguous memory allocation
// capacity of a vector increses in the power of 2
// in resizing the capacity increases depending upon the compiler
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    cout<<"Size: "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl;
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;

    v.push_back(1);
    cout<<"Size: "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl;
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;

    v.push_back(2);
    cout<<"Size: "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl;
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;

    v.push_back(3);
    cout<<"Size: "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl;
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;

    v.resize(5);
    cout<<"Size: "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl;
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;

    v.resize(10);
    cout<<"Size: "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl;
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;

    v.pop_back();
    cout<<"Size: "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl;
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;
    
    v.pop_back();
    cout<<"Size: "<<v.size()<<endl;
    cout<<"Capacity: "<<v.capacity()<<endl;
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;

    return 0;
}