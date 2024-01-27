#include<iostream>
using namespace std ;

class Fraction{
  private:

  int numerator;
  int denominator;

  public:

  void display(){

    cout<<numerator<< "/" << denominator<<endl;
  }
  Fraction(int numerator,int denominator){
    this->numerator = numerator;
    this->denominator = denominator;
  }
  
  void add(Fraction f){
    this->numerator = numerator*f.denominator+denominator*f.numerator ;
    denominator = denominator*f.denominator ;
    simplify();
  }
  void simplify(){
    int x;
    int y = min(numerator,denominator);
    for(int z = 1 ;z <= y ; z++){
      if(numerator%z == 0 && denominator%z == 0)
        x = z; 
    }
    numerator = numerator/x;
    denominator = denominator/x;
  }
  
};

int main(){
  Fraction f1 = Fraction(15,4);
  Fraction f2 = Fraction(10,2);
  f1.add(f2);
  f1.display();

return 0;
}