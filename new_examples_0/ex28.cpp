#include<iostream>
using namespace std;
void consrem(char *c){
    if(c[0] == '\0')
     return;
    if(c[0] == c[1]){
        for(int x = 1 ;  c[x] != '\0' ; x++){
         c[x]=c[x+1];
        }
    consrem(c);
    }
    else 
     consrem(c+1);
}
int main(){
    char str[50];
    cin>>str;
    consrem(str);
    cout<<str;
}