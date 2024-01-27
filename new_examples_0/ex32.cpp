#include<iostream>
#include<string>
using namespace std;

int jumps(int n){
    if(n == 0)
     return 1;
    if(n == 1)
      return 1;
    if(n == 2)
      return 2;
   return jumps(n-1)+jumps(n-2)+jumps(n-3);
}

int jumps2(int n){
    if(n == 0 || n == 1)
     return 1;
    if(n < 0)
     return 0;
    return jumps(n-1)+jumps(n-2)+jumps(n-3);  
}

int main(){
int n;
cin>>n;
int ans = jumps(n);
cout<<ans;

return 0;
}