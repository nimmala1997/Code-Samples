#include<stdio.h>

int lostInForest(int input1)
{
    int x = 0;
    int a,b,d = 0;
    int c = 0 ;
    for(int y = 3 ;  y <= input1 ; y++ ){
        a = 0;
        d = y;
        if(d%2 != 0){
            while(d != 1){
                if(d % 2 != 0){
                    d = 3*d + 1;
                }
                else{
                    d = d/2;
                }
             a++;
            }
            if(a > b){
             b = a ;
             c = y ;
            }
        }
    }
return c;
}

int main(){
    int c,d;
    scanf("%d",&d);
    c = lostInForest(d);
    printf("%d",c);

return 0; 
}