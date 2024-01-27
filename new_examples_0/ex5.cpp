#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int i = str.length();
    //cout<<str;
    //cout<<str.length();
    int k = 2*i - 1;
    //cout<<k;
    int a,c;
    vector<char> row(k);
    vector< vector<char> >vec(i,row);
    
    for(int x = 0;x < i;x++)
    {   c = 0;
        for(a = 0 ; a < ((k/2)-x); ++a)
        {
          cout<<' ';
        }
        for(int b = a ; b <= k/2 ; ++b)
        {
            cout<<str.at(c);
            ++c;
        }
        c = c-2;
        
        while(c>=0)
        {
           cout<<str.at(c);
           c--;
        }
        cout<<endl;
    }
    return 0;
}