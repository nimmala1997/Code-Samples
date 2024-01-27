#include<iostream>
#include<string>
#include<string.h>

using namespace std;

void printsubstr(string input,string output){
    if(input.length() == 0){
     cout<<output<<endl;;
     return;
    }
    printsubstr(input.substr(1),output);
    printsubstr(input.substr(1),input[0]+output);
}

int main(){
string str;
cin>>str;
string output = " ";
printsubstr(str,output);
return 0;
}