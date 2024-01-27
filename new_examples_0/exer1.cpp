#include<iostream>
#include<string>

using namespace std;
int min(string s){
    int a = s.length();
    int b = a - 1;
    int c = 0 ;
    while(c < b && s[c] == s[b]){
       char d = s[c];
       while(c <= b && s[c] == d) 
           c++ ;
        while(c <= b && s[b] == d) 
           b-- ;

       }
       return b - c + 1 ;
    }

int main(){
    string s;
    cin>>s;
    int d = min(s);
    cout<<d;
    
}