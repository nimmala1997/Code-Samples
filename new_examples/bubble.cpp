#include<iostream>
using namespace std;
class solution{
    public:
   void bubblesort(int arr[],int n){
    int k;
    for(int i = 0; i  < n ; n--){
        for(int j = 0 ; j < n-1; j++){
            if(arr[j]>arr[j+1]){
                k = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = k;
            }
        }
    }
   }
};
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int x =0;x<n;x++)
     cin>>arr[x];
    solution s1;
    s1.bubblesort(arr,n);
    for(int x = 0; x < n;x++){
        cout<<arr[x]<<" ";
    }
return 0;
    
}