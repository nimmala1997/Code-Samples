#include<stdio.h>
struct array
{
    int a[10];
    int size;
    int length;
};
void display(int *a,int n)
{
  for(int x = 0;x<n;x++){
      printf("%d ",a[x]);
  }
}
void swap(int *x,int *y)
{
    int temp ;
    temp = *x;
    *x = *y;
    *y = temp;
}

void arraysort(int *a,int n){
    int i = 0;
    int j = n-1 ;
    while(i < j)
    {
      while(a[i]< 0)
       i++ ;
       while(a[j]>0)
       j--;
       if(i < j)
        swap(&a[i],&a[j]);
    }
     
}

int main()
{
    
    struct array arr1 = {{-6,3,-8,10,5,-7,-9,12,-4,2},10,10} ;
    arraysort(arr1.a,arr1.length);
    display(arr1.a,arr1.length);

return 0;
    
}