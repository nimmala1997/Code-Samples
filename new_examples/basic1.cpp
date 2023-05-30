#include <iostream>
using namespace std;

int main()
{
    int no_of_rooms;
    cin>>no_of_rooms ;
    cout<<"price per room is $30 "<<endl ;
    cout<<"total price is $"<<no_of_rooms*30<<endl;
    float tax = 0.06*no_of_rooms*30;
    //cout<<tax<<endl;
    cout<<"total estimate is $"<<tax+no_of_rooms*30<<endl;
    cout<<"this estimate is valid is 30 days";

    return 0;
}