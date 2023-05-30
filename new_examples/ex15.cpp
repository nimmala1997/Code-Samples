#include<iostream>

using namespace std;

int sum(int n){
    if(n/10 == 0)
      return n;
    
    int small = sum(n/10);

    int ans = small+(n%10);
    return ans;
}
int main(){
    int n ;
    cin>>n;
    int ans = sum(n);
    cout<<ans;

return 0;
}