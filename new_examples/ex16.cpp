#include<iostream>
using namespace std;

int mul(int m,int n){
    if(n ==1)
     return m;
    int small = mul(m,n-1);
    int ans = small+m;
    return ans;
}

int main(){
    int m;
    int n;
    cin>>m>>n;
    int ans  = mul(m,n);
    cout<<ans;
}