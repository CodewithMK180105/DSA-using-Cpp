#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<int,string> students; // rollno. and name

    students[3]="Mann";
    students.insert(make_pair(2,"Manishkumar"));
    students[1]="Manav";

    for(auto student: students){
        cout<<"Roll no. "<<student.first<<", Name: "<<student.second<<endl;
    }
    return 0;
}
