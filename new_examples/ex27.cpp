#include<iostream>
using namespace std;
void remove(char *c,char a){
    if(c[0] == '\0')
     return ;
    if(c[0] != a)
     remove(c+1,a);
    else
     if(c[0] == a){
         for(int x = 0 ;c[x] != '\0';x++){
          c[x] = c[x+1];
         }
     remove(c,a);
     }
}
int main(){
    char str[100];
    cin>>str;
    remove(str,'a');
    cout<<str;
}