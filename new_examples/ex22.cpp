#include<iostream>

using namespace std;
int count(int *a,int n,int x,int i){
    if(i == n)
     return 0;
    if(a[i] == x)
     return 1 + count(a,n,x,i+1);
    else
      return count(a,n,x,i+1);
}
int main(){
    int n ;
    cin>>n;
    int a[n];
    for(int x = 0; x < n;x++){
        cin>>a[x];
    }
    int x;
    cout<<"enter number";
    cin>>x;
    int ans = count(a,n,x,0);
    cout<<ans;

return 0;
}