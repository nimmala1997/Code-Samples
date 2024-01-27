#include<iostream>
using namespace std;

bool ispresent(int arr[],int n,int x,int i){
    if (i == n )
     return false;
    if (arr[i] == x)
     return true;
    cout<<i;
   return ispresent(arr,n,x,i+1);
}


int main(){
    int arr[] = {1,2,3,4,5};
    bool ans = ispresent(arr,5,4,0);
    cout<<ans;

return 0;
}