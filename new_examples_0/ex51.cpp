#include<iostream>
using namespace std;
int ans(int x,int c){
    if(x == c)
     return 2000000000;
     if(c == 1)
     return x;
      if(x > c){
      int i;
       for(i = x-1; i > 1;i--){
         if(((x/i) + (x%i)) == c)
          return i;
      }
      }
     return -1;
    
}
int main(){
    int x,y;
    cin>>x>>y;
    int c = ans(x,y);
    cout<<c;

return 0;
}