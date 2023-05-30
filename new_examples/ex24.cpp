#include<iostream>

using namespace std;

bool checkpalin(int *a,int s,int e){
    if(s > e)
      return true;
    if(a[s] == a[e])
     return checkpalin(a,s+1,e-1);
    else
     return false;
}
int main(){
     int n ;
    cin>>n ;
    int a[n];
    for(int x = 0; x < n;x++){
        cin>>a[x];
    }
    bool ans = checkpalin(a,0,n-1);
    cout<<ans;
}