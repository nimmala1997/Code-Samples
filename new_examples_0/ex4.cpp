#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
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
          vec.at(x).at(a) = ' ';
        }
        for(int b = a ; b <= k/2 ; ++b)
        {
            vec.at(x).at(b) = str.at(c);
            ++c;
        }
    }
    for(int d = 0 ; d < i ; d++)
    {
        for(int e = (k/2)+1 ; e < k ; e++)
        {
          vec.at(d).at(e) = vec.at(d).at((k - 1) - e);
        }
    }
    for(int f = 0; f < i ; f ++){
        for(int g = 0 ; g < k ; g++ ){
            cout<<vec.at(f).at(g);
        }
        cout<<endl;
    }

return 0;
}