#include<iostream>
#include<string>
#include<string.h>

using namespace std;

void printsub(string st,string out){
    if(st.length() == 0){
     cout<<out;
     return;
    }
    printsub(st.substr(1),out);
    printsub(st.substr(1),out+st[0]);
}

int main(){

    string st = "abc";
    string emp = " ";
    //cout<<st.length();
    printsub(st,emp);

return 0;
}