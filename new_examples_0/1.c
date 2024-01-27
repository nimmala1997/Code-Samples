#include<stdio.h>

int main(){
    int a[4];
    int b[4];
    printf("enter a elements");
    for(int x =0 ; x < 4 ; x++){
        scanf("%d",&a[x]);
    }
    printf("enter b elemets");
    for(int x = 0; x < 4 ;x++){
        scanf("%d",&b[x]);
    }
    int c[4];
    for(int x = 0 ; x < 4;x++){
        c[x] = a[x]+b[x];
    }
    for(int x = 0; x< 4 ; x++){
        printf("%d " , c[x]);
    }
}