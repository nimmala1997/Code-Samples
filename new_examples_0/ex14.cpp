#include<iostream>

using namespace std;

 int count(int n){
    if(n >= 1){
     if ( n/10 == 0)
      return 1;
    int small = count(n/10);
    int ans = small+1;
    return ans; 
     }
 }

int main(){
    int n;
    cin>>n;
    int ans = count(n) ;
    cout<<ans;

return 0;
    
}