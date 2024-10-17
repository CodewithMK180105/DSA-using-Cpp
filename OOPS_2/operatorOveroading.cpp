#include<iostream>
using namespace std;
class Fraction{
    public:
        int numerator;
        int denominator;
        Fraction(int numerator, int denominator){
            this->numerator=numerator;
            this->denominator=denominator;
        }
        void display(){
            cout<<numerator<<"/"<<denominator<<endl;
        }
        // Fraction add(Fraction f){
        //     int newNumerator=this->numerator*f.denominator+this->denominator*f.numerator;
        //     int newDenominator=this->denominator*f.denominator;
        //     Fraction ans(newNumerator,newDenominator);
        //     return ans;
        // }
        Fraction operator+(Fraction f){
            int newNumerator=this->numerator*f.denominator+this->denominator*f.numerator;
            int newDenominator=this->denominator*f.denominator;
            Fraction ans(newNumerator,newDenominator);
            return ans.simplify();
        }
        Fraction operator-(Fraction f){
            int newNumerator=this->numerator*f.denominator-this->denominator*f.numerator;
            int newDenominator=this->denominator*f.denominator;
            Fraction ans(newNumerator,newDenominator);
            return ans.simplify();
        }
        Fraction operator*(Fraction f){
            int newNumerator=this->numerator*f.numerator;
            int newDenominator=this->denominator*f.denominator;
            Fraction ans(newNumerator,newDenominator);
            return ans.simplify();
        }
        Fraction operator/(Fraction f){
            int newNumerator=this->numerator*f.denominator;
            int newDenominator=this->denominator*f.numerator;
            Fraction ans(newNumerator,newDenominator);
            return ans.simplify();
        }
        int gcd(int a,int b){
            if(b==0) return a;
            else return gcd(b,a%b);
        }
        Fraction simplify(){
            int gcdValue=gcd(numerator,denominator);
            numerator/=gcdValue;
            denominator/=gcdValue;
            return *this; // returns the current instance
        }
};
int main() {
    Fraction f1(1,4);
    f1.display();
    Fraction f2(1,2);
    f2.display();
    // Fraction f3=f1.add(f2);
    Fraction f3=f1+f2;
    f3.display();
    Fraction f4=f1-f2;
    f4.display();
    Fraction f5=f1*f2;
    f5.display();
    Fraction f6=f1/f2;
    f6.display();
    return 0;
}