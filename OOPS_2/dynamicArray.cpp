#include<iostream>
using namespace std;
class Vector{
    public:
    int size;
    int capacity;
    int *arr;

    Vector(){
        size=0;
        capacity=1;
        arr=new int[1];
    }
    void add(int ele){
        if(size==capacity){
            capacity*=2;
            int* arr2=new int[capacity];
            for(int i=0;i<capacity;i++){
                arr2[i]=arr[i];
            }
            arr=arr2;
        }
        arr[size++]=ele;
    }

    int get(int idx){
        if(idx<0 || idx>=size){
            cout<<"Invalid Index";
            return -1;
        }
        else if(size==0){
            cout<<"Vector is empty";
            return -1;
        }
        return arr[idx];
    }

    void remove(){
        if(size==0){
            cout<<"Vector is empty";
            return;
        }
        size--;
    }
    
    void print(){
        for(int i=0;i<size;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Vector v;
    cout<<v.get(0)<<endl;
    // cout<<v.size<<" "<<v.capacity<<endl; // 0 1
    v.add(1);
    v.print();
    // cout<<v.size<<" "<<v.capacity<<endl; // 1 1
    v.add(2);
    v.print();
    // cout<<v.size<<" "<<v.capacity<<endl; // 2 2
    v.add(3);
    v.print();
    // cout<<v.size<<" "<<v.capacity<<endl; // 3 4
    v.add(4);
    v.add(5);
    v.add(6);
    v.add(7);
    cout<<v.get(5)<<endl;
    v.print();
    v.remove();
    v.remove();
    v.remove();
    v.print();
    return 0;
}