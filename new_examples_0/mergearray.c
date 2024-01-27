#include<stdio.h>
#include<stdlib.h>

struct array {
int a[10];
int length;
int size;
};

void display(int *arr,int y)
{
    for(int x = 0; x < y ; x++)
        printf("%d ",arr[x]);
    
}

int *merge(int a[],int b[],int y)
{
    int i = 0;
    int j = 0;
    int *c;
    c = (int *)malloc(y*sizeof(int));

    for(int x = 0; x < y; x++)
    {
        if(i < 5 && j < 5 )
        {
        if(a[i]<b[j])
        {
            c[x] = a[i];
            i++;
        }
         else
          if(a[i]>b[j])
        {
            c[x] = b[j];
            j++;
        }
         
        }
        else
         if(a[i] > b[j])
             c[x] = a[i];
         else
          c[x] = b[j];
    }
    return c;
}

int main(){

struct array arr1 = {{3,8,16,20,25},5,5} ;
struct array arr2 = {{4,10,12,22,23},5,5} ;

int *d = merge(arr1.a,arr2.a,10);

display(d,10);

return 0;

}