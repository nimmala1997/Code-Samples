#include<iostream>
using namespace std;

int main()
{
    int small;
    int large;
    cout<<"enter no.of small rooms ";
    cin>>small;
    cout<<"enter no.of large rooms ";
    cin>>large;
    cout<<"cost for small room is $25\ncost for large room is $35"<<endl;
    cout<<"total cost is $"<<(25*small)+(35*large)<<endl;
    cout<<"tax is $"<<0.06*((25*small)+(35*large))<<endl;
    cout<<"total estimate is $"<<0.06*((25*small)+(35*large))+(25*small)+(35*large)<<endl;
    cout<<"esitmate is valid for 30 days"<<endl;

    return 0;
}