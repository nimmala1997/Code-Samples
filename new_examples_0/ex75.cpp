#include <iostream>
using namespace std;

void removechar(char arr[],int n,char a,int i){
   if(i == n)
    return;
   if(arr[i] == a){
     for(int k = i;arr[k] != '\0';k++)
        arr[k] = arr[k+1];
        removechar(arr,n-1,a,i);
    } 
   else{
        removechar(arr,n,a,i+1);
    }
}
int main() {
   char arr[] = {'a','a','b','c','a','b','\0'};
   removechar(arr,6,'a',0);
   for(int i = 0; i < 6;i++)
     cout<<arr[i];
return 0;
}