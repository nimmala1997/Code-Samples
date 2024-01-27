#include<iostream>
#include<string>
using namespace std;

int main()
{
    string name;
    string pass;
    getline(cin,name);
    getline(cin,pass);

    cout<<name<<" "<<pass;

return 0;
}