#include<iostream>
#include<vector>
using namespace std;
class s

int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    vector <int> row(n);
    vector < vector <int>> array(n,row);
    cout<<"enter matrix";
    for (int i = 0; i < n; i++)
    {
     for (int x = 0; x < n; x++)
     {
        cin>>array.at(i).at(x);
     }
     }
     
    
}