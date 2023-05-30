#include<iostream>
using namespace std;
bool sort(int *arr,int n){
    if(n == 0 || n == 1)
    return true;

    if(arr[0] > arr[1])
    return false;

   bool ans = sort(arr+1,n-1);
   
   return ans;

}

int main (){
    int n;
    cin>>n;
    int arr[n];
    for(int x =0;x < n;x++){
        cin>>arr[x];
    }
    bool ans;
    ans = sort(arr,n);
    cout<<ans;

return 0;
}