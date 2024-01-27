#include<iostream>

using namespace std;

int length(char *c){
    if(c[0] == '\0')
     return 0;
    else
     return 1+length(c+1);
}
void replace(char c[],char a,char b){
    if(c[0] == '\0')
     return;
    if(c[0] == a)
     c[0] = b;
    replace(c+1,a,b);    
}
int main(){
    char str[100];
    cin>>str;
    int l = length(str);
    cout<<l;
    cout<<str<<" ";
    replace(str,'a','b');
    cout<<str;


return 0;
}