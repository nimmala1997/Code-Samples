#include<iostream>
using namespace std;
void print(char *arr){
if(arr[0] == '\0' )
 return;
cout<<arr[0];
print(arr+1);
}
void revprint(char *arr){
if(arr[0] == '\0' )
 return;
revprint(arr+1);
cout<<arr[0];
}
int lenchar(char arr[]){
    if(arr[0] == '\0')
     return 0;
    return 1+lenchar(arr+1);
}

int main(){
    char arr[] = {'a','b','c'};
    char arr1[100];
    cin>>arr1;
    //revprint(arr);
    int ans = lenchar(arr1);
    cout<<ans;


return 0;
}