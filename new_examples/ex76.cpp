#include <iostream>
using namespace std;

void removechar(char* arr,int n){

   if(arr[0] == '\0'){
     //cout<<"ent";
     return;
   }
   
   if(arr[0] == arr[1]){
      //cout<<"ent";
      for(int k = 0; arr[k] != '\0'; k++)
        arr[k] = arr[k+1];
        //cout<<"ent";
        removechar(arr,n);
   }
   else
     removechar(arr+1,n);
}
int main(){
   int n;
   cin>>n;
   char arr[n];
   cin>>arr;
   removechar(arr,n);

   for (int i = 0 ; arr[i] != '\0'; i++){
      cout<<arr[i];
   }
   
}
