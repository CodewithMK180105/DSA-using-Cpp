// Create a class "Book" with name, price and number of pages as it's attributes. The class should contain following member functions.
// 1. comparePrice(int price): This function will return 1 if the price of the book is less than the given price else 0.
// 2. isBookPresent(string title): This will return a boolean value indicating whether any book with the given title is present.

#include<iostream>
using namespace std;
class Book{
    public:

        string name;
        int price;
        int nop;

        int comparePrice(int p){
            if(price<p) return 1;
            else return 0;
        }

        bool isPresent(string title){
            if(name==title){
                return true;
            } else{
                return false;
            }
        }
};
int main(){
    Book b;
    b.name="Software";
    b.price=8000;
    b.nop=5004;

    cout<<b.comparePrice(10000)<<endl;
    cout<<b.isPresent("Physics");
    return 0;
}