#include<iostream>
using namespace std;

int main()
{
int n;
cin>>n;
int p,r;
p = n/100;r=n%100;
cout<<"\ndollars: "<<p;
p = r/25;r  = r%25;
cout<<"\nquarters: "<<p;
p = r/10;r = r%10;
cout<<"\ndime: "<<p;
p = r/5;r = r%5;
cout<<"\nnickel: "<<p;
p = r/1;r = r%1;
cout<<"\npennies: "<<p;

return 0;

}