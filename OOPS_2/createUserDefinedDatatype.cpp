#include<iostream>
using namespace std;
class Student{
    public:
        string name;
        int rno;
        float gpa;
};
int main(){

    Student s1;
    s1.name="Manishkumar Munnalal Gupta";
    s1.rno=92;
    s1.gpa=9.1925;
    
    Student s2;
    s2.name="Raghav Garg";
    s2.rno=76;
    s2.gpa=9.5;

    cout<<s1.name<<" "<<s1.rno<<" "<<s1.gpa<<endl;
    cout<<s2.name<<" "<<s2.rno<<" "<<s2.gpa<<endl;
    
    return 0;
}