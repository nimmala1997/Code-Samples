#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    float inp[n];
    float out[n];
    float ans[n];
    for(int x = 0 ; x< n ; x++){
        cin>>inp[x];
    }
    for(int x = 0 ; x < n ; x++){
        cin>>out[x];
    }
    for (int i = 0; i < n; i++)
    {
        ans[n] = 0.0;
    }
    ans[0] = out[0];
    int a = 0;
    int y = 0;
    for(int x = 1 ; x < n; x++){
        for( y = 0; y <= a;y++)
        {
        if(inp[x]>ans[y]){
            ans[y] = out[x];
            cout<<ans[a];
            break;
         }
       }
        if( y == a && ans[a] != out[x]){
           a++;
           ans[a] = out[x];
           cout<<ans[a];
        }
    }
    for(int x = 0; x < n;x++){
        cout<<ans[x];
    }

return 0;
    
}