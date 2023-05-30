#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int main(){
    vector<string> stooges {"Haary","hermonine","westly"};

    for(string const x : stooges){
       // x = "food";
    }
    for(auto y : stooges){
        cout<<y<<endl;
    }

return 0;
} 