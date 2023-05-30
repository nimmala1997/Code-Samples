#include<iostream>
using namespace std;

void remchar(char arr[],char x){
    if(arr[0] == '\0')
     return;
    
    if(arr[0] == x){
     for(int i = 0;arr[i] != '\0';i++){
        arr[i] = arr[i+1];
     }
    remchar(arr,x);
    }
    else
    remchar(arr+1,x);
}

int main(){
    char arr[100];
    cin>>arr;
    remchar(arr,'a');
    cout<<arr;

return 0;
}