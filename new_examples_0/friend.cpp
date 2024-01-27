#include<iostream>
#include<algorithm>
#include<string>

using namespace std ;

int main(){
    int n;
    int m;
    cin>>n;
    cin>>m;
    string arr[n*m];
    for(int x = 0;x < m*n;x++){
        cin>>arr[x];
    }
    sort(arr,arr+m*n);
    int a = 0;
    for(int x = 0 ;x < n*m ; x++){
        int j = 0;
        for(j = 0; j < x; j++)
            if(arr[x] == arr[j])
              break;
            if( x == j)
             a++;   
        
    }
    cout<<a;

 return 0;
}