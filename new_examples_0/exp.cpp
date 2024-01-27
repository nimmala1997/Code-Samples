#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cin>>n;
    char arr[n];
    for(int x =0 ;x < n;x++)
     cin>>arr[x];
    for(int x =0 ;x < n;x++)
     cout<<arr[x];
}
