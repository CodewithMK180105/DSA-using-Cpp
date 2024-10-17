#include<iostream>
using namespace std;
class Student{
    public:
        int rno;
        string name;
        void display(){
            cout<<name<<" "<<rno<<" "<<marks<<endl;
        }
        Student(){

        }
        Student(int rno,string name,float marks){
            this->rno=rno;
            this->name=name;
            this->marks=marks;
        }
        float getMark(){ // getter (private member can be accessed)
            return marks;
        }
        void setMark(int marks){ // setter (private member can be modified)
            this->marks=marks;
        }
    private:
        float marks;
};
int main(){
    Student s1;
    s1.rno=92;
    s1.name="Manishkumar";
    s1.display();
    // s1.marks=95; // Private member cannot be accessed directly
    // cout<<s1.marks<<endl; // Private member cannot be read directly
    s1.setMark(95);

    Student s2(76,"Raghav",90);
    s2.display();

    cout<<s1.getMark()<<endl;
    cout<<s2.getMark()<<endl;

    return 0;
}