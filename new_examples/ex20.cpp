#include<iostream>
using namespace std;
int index(int *a,int n,int x,int i){
    if(i == -1)
     return -1;
    if(a[i]== x)
     return i;
    return index(a,n,x,i+1);
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
    int ans = index(a,n,x,0);
    cout<<ans;
}