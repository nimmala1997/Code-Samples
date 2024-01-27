#include<iostream>

using namespace std;

 void print(char *c){
     if(c[0] == '\0')
      return;
    cout<<c[0];
    print(c+1);
 }
  void revprint(char *c){
     if(c[0] == '\0')
      return;
    print(c+1);
    cout<<c[0];
 }
int main(){
    int n;
    cin>>n;
    char str[n];
    for(int x = 0; x < n;x++){
        cin>>str[x];
    }
    print(str);
    cout<<" ";
    revprint(str);

return 0;

}