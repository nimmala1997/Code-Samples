#include<stdio.h>
struct array
{
    int a[10];
    int size;
    int length;
};
void display(struct array arr){
    for(int x = 0; x < arr.size ; x++)
        printf("%d ",arr.a[x]);
    
}
void swap(int *p,int *q){
    int c;
    c = *p;
    *p = *q;
    *q = c;
}
int linearsearch(struct array *ptr,int x){
     for(int i = 0; i < ptr->length ; i++){
         if(x == ptr->a[i]){
             swap(&ptr->a[i],&ptr->a[0]);
            return i ;
         }
     }
     return -1 ;
}

int main(){
  struct array arr1={{2,23,14,5,6,9,8,12},10,8};
  printf("%d",linearsearch(&arr1,14));
  printf("\n");
  display(arr1);
 
return 0;
}