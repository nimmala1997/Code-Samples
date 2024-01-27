#include <iostream>
using namespace std;

bool prime(int A){
    int ans = 0;
    for (int i = 2; i < A/2; i++){
        if(A%i == 0){
         ans++; 
         break;
        }
    }
    if(ans > 0)
     return false;
    else
     return true;
}
int main (){
   int a; 
   cin>>a;
   bool ans = prime(a);
   cout<<ans;

return 0;
}