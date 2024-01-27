#include<iostream>

using namespace std;

int soar(int arr[],int n){
    if(n == 0)
     return 0;
    return arr[0]+soar(arr+1,n-1);
}

int main(){

    int arr[] = {1,2,3,4,5};
    int ans = soar(arr,5);
    cout<<ans;

return 0;
}