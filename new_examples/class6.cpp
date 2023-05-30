#include<iostream>
using namespace std;

void selecsort(int a[],int n){
  int b ;
  for(int c = 0; c < n-1 ; c++){
      for(int d = c+1; d < n ;d++){
          if(a[c] > a[d]){
              b = a[c];
              a[c]= a[d];
              a[d] = b;
          }
      }
  }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int x = 0;x < n;x++)
       cin>>a[x];
    selecsort(a,n);
    for(int x = 0;x < n;x++)
     cout<<a[x]<<" ";
}