#include<stdio.h>
struct array {
 int a[10];
 int size;
 int length;
};
void display(struct array Arr){
    for(int x = 0; x < Arr.size ; x++)
        printf("%d ",Arr.a[x]);
    
}
/*int BinarySearch(struct array arr,int x){
int l=0,mid,h;
h = arr.length - 1 ;
while (l <= h)
{ 
    mid = (l+h)/2 ;
    if (arr.a[mid] == x)
     return mid;
     else 
       if(arr.a[mid] > x)
        h = mid-1 ;
        else
         l = mid+1;
}
return -1 ;

} */

int RBinarySearch(int arr[],int x,int l, int h){
    int mid = 0;
    if(l <= h){
    mid = (l+h)/2 ;
   if(arr[mid] == x)
    return mid;
    else
    if(x > arr[mid])
    {
      l = mid+1;
      return RBinarySearch(arr,x,l,h);
    }
    else
     if(x < arr[mid])
     {
         h = mid - 1;
         return RBinarySearch(arr,x,l,h);
     }
   }
   else
    return -1;
}

int main(){
 
 struct array arr1={{2,3,9,16,18,21,28,32,35},10,9};
 printf("%d",RBinarySearch(arr1.a,16,0,arr1.length -1));
 printf("\n");
 display(arr1);
 
return 0;
}