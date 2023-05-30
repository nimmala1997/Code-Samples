#include<iostream>
using namespace std;

class Fraction{
    int num;
    int den;
   
   public:
  Fraction add(Fraction f){
    int lcm = den*f.den;
    int numer = f.den*num+f.num*den;
   
    Fraction fnew(numer,lcm);

    fnew.simplify();
    return fnew;

  }
  void simplify(){
    int gcd = 1;
    for(int i = 1;i <= den;i++){
        if(num%i == 0 && den %i == 0)
         gcd = i;
    }
    num = num/gcd;
    den = den/gcd;
  }
  Fraction(int num,int den){
    this->num = num;
    this->den = den;
  }
  void display(){
    cout<<num<<'/'<<den<<endl;
  }
};

int main(){
    Fraction f1(10,2);
    Fraction f2(15,4);

    Fraction f3 = f1.add(f2);
    f3.display();

return 0;
}