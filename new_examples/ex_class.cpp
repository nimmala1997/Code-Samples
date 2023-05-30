#include<iostream>
#include<string>
#include<vector>
using namespace std;
class player
{
    public:
    string name{"Default"};
    int health{180};
    int xp{3};

    void talk(string name);
    bool is_dead();
};
class Account
{
    public:
    string name{"Default"};
    double balance{0};

    bool deposit(double x);
    bool withdraw(double y);

};
void player::talk(string excl)
{
    cout<<name<<" Says HI "<<excl<<endl;

}
int main()
{ 
    player pavan;
    player kalyan;

    player *nimmala = new player;

    Account pavan_account;
    Account Kalyan_account;

    pavan.name = "Kalyan";
    pavan.talk("NPK");

    //pavan.name = "Pavan";
    //cout<<nimmala->name<<endl;

 

    player enemy[] = {pavan,kalyan} ;
    //enemy = {pavan,kalyan};

return 0;
}