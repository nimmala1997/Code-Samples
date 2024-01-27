#include<iostream>

using namespace std;
int lastindex(int *a,int n,int x,int i){
    if(i == n)
     return -1;
    int small = lastindex(a,n,x,i+1);
    if(small == -1){
         if(a[i]==x)
          return i;
        else
          return -1;
    }
    else 
     return small;
}
int main(){
     int n ;
    cin>>n;
    int a[n];
    for(int x = 0; x < n;x++){
        cin>>a[x];
    }
    int x;
    cout<<"enter number to find index";
    cin>>x;
    int ans = lastindex(a,n,x,0);
    cout<<ans;
}