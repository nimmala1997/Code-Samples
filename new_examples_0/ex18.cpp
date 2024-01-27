#include<iostream>

using namespace std;

int sum(int *arr,int n){
    if(n == 0)
     return 0;
    int small = sum(arr,n-1);

    int ans = small+arr[n-1];

    return ans ;
}
int sum1(int *arr,int n,int i){
    if(i == n)
     return 0;
    int ans = arr[i] + sum1(arr,n,i+1);
    return ans;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int ans = sum(arr,5);
    cout<<ans;

return 0;
}