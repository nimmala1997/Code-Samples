#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    double inp[n];
    double out[n];
    double ans[n];
    for(int x = 0 ; x< n ; x++){
        scanf("%lf",&inp[x]);
    }
    for(int x = 0 ; x < n ; x++){
        scanf("%lf",&out[x]);
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
            break;
         }
       }
        if( y-1 == a && ans[a] != out[x]){
           a++;
           ans[a] = out[x];
        }
    }
    for(int x = 0; x < n;x++){
        printf("%lf",ans[x] );
        printf(",");
    }

return 0;
    
}