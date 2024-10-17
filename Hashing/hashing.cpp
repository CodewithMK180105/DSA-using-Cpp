#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

class Hashing{

public:

    vector<list<int>> hashtable;
    int buckets;

    Hashing(int size){
        buckets=size;
        hashtable.resize(size);
    }

    int hashValue(int key){
        return key%buckets;
    }

    void add(int key){
        int idx=hashValue(key);
        hashtable[idx].push_back(key);
    }

    list<int>::iterator search(int key){
        int idx= key%buckets;
        return find(hashtable[idx].begin(),hashtable[idx].end(),key); // return the iterator in which the key is present else returns the hashtable[idx].end() if the key is not present
    }

    void deleteKey(int key){
        int idx=hashValue(key);
        if(search(key)!=hashtable[idx].end()){
            hashtable[idx].erase(search(key));
            cout<<key<<" deleted"<<endl;
        }
        else{
            cout<<key<<" is not present"<<endl;
        }
    }
};

int main(){
    Hashing h(10);
    h.add(5);
    h.add(9);
    h.add(3);
    h.deleteKey(3);
    h.deleteKey(3);
    return 0;
}