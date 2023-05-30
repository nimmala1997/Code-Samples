#include<iostream>
using namespace std;

bool present(int *a,int n,int x){
    if(n == 0)
     return false;
    if (a[0] == x) 
      return true;
    return present(a+1,n-1,x);
}
bool present2(int *a,int n,int x){
    if(n == 0)
     return false;
    if(present2(a+1,n-1,x))
     return true;
    if(a[0] == x)
      return true ;
    else
      return false; 
}
bool present3(int *a,int n,int x,int i){
    if (i == n)
     return false;
    if (a[i] == x)
     return true;
    return present3(a,n,x,i+1);
}
int main(){
 int n;
 cin>>n;
 int a[n];
 for(int x = 0 ; x < n;x++){
     cin>>a[x];
 }
 cout<<"number to check";
 int x;
 cin>>x;
 bool ans = present3(a,n,x,0);
 cout<<ans;
}