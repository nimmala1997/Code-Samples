#include<stdio.h>
#include<stdlib.h>
void append(int *a,int b,int c){
    a[c] = c+1;
}
void insert(int *a,int n,int d,int b,int c){
    for(int x = d ; x > b ; x--){
        a[x] = a[x-1];
        }
        a[b] = c;
}
int main(){
    int *p;
    int n;
    scanf("%d",&n);

    p = (int *)calloc(n,sizeof(int));
    
         for(int x = 0; x < 5 ; x++){
             p[x] = x+1;
         }

     append(p,10,5);
      for(int x = 0; x < 6 ; x++){
             printf("%d",p[x]);
         }
         printf("\n");
    insert(p,10,6,4,3);
    for(int x = 0; x < 7 ; x++){
             printf("%d",p[x]);
         }
return 0;

}