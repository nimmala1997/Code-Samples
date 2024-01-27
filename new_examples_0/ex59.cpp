#include<iostream>
using namespace std;

void repchar(char arr[]){
if(arr[0] == '\0')
 return ;
if(arr[0] != arr[1])
 repchar(arr+1);
else{
 for(int i = 0;arr[i] != '\0'; i++){
    arr[i] = arr[i+1];
   }
 repchar(arr);
}
}
int main(){
    char arr[100];
    cin>>arr;
    repchar(arr);
    for(int i = 0 ; arr[i] != '\0';i++)
     cout<<arr[i];

return 0;

}