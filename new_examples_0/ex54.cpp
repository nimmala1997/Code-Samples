#include<iostream>

using namespace std;

int nod(int n){
  if(n/10 == 0)
  return 1;
  return 1+nod(n/10);
}

int main(){
    int n;
    cin>>n;
    int ans = nod(n);
    cout<<ans;

return 0;
}