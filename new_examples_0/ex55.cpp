#include<iostream>

using namespace std;
int sod(int n){
    if(n == 0)
     return 0;
    return n%10 + sod(n/10);
}
int main(){
    int n ; 
    cin>>n;
    int ans = sod(n);
    cout<<ans;

return 0;
}