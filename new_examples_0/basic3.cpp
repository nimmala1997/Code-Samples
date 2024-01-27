#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec;
    
    char c;
    int x ;
    int a = 1;
    while(a > 0)
  {
    cout<<"Menu\nP - Display list\nA - adds element to list";
    cout<<"enter character";
    cin >> c;
    if(c == 'P' || c == 'p'){
        if(vec.size() > 0)
           for(int i = 0 ; i < vec.size() ; i++){
             cout<<vec.at(i);
              }
        else
         cout<<"No list to display\n";
    }
    if(c == 'A' || c == 'a'){
        cout<<"enter an integer\n";
        cin >> x;
        vec.push_back(x);    
    }
    if(c == 'Q'|| c == 'q')
     break;
  }
  cout<<"Thank you";

}