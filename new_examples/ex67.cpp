#include<iostream>
using namespace std;

int occ(int *arr,int x,int n){
    int ans;
    int s = 0,e = n-1;
    int mid = (s+e)/2;
    if(arr[s] == x)
     return s;
    while(s<=e){
        mid = (s+e)/2;
        if(arr[mid] == x && arr[mid] > arr[mid-1]){
           return mid;
        }
        else
         if(arr[mid] < x){
          s = mid+1;
         }
        else{
          e = mid-1;
        }
    }
    return -1;
    


}
int occ2(int *arr,int x,int n){
    int ans;
    int s = 0,e = n-1;
    int mid = (s+e)/2;
    if(arr[e] == x)
     return e;
    while(s<=e){
        mid = (s+e)/2;
        if(arr[mid] == x && arr[mid] < arr[mid+1]){
           return mid;
        }
        else
         if(arr[mid] > x){
          e = mid-1;
         }
        else{
          s = mid+1;
        }
    }
    return -1;

}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0 ; i < n ; i++){
       cin>>a[i];
    }
    int x1;
    cin>>x1;
    int ans = occ2(a,x1,n);
    cout<<ans;

return 0;
}