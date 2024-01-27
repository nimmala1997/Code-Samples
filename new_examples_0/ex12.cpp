#include<iostream>

using namespace std;

int powe(int a, int b){
      if(b == 0)
       return 1;
       if(b == 1)
       return a;
      
      int small = powe(a,b-1);

      int ans = a*small;
      return ans;
}

int main(){
     int n,p;
     cin>>n>>p;
     int ans = powe(n,p);
     cout<<ans;
return 0;
}