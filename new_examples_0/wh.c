  #include<stdio.h>
  int main(){
  int y = 3;
  int a = 0;
  while(y != 1){
               
     if(y % 2 != 0)
     {
      y = 3*y + 1;
      }
     else{
         y = y/2;
        }
    a++;
    printf("%d",a);
    }
return 0;
  }