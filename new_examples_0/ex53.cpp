#include<iostream>
using namespace std;

void bubblesort(int *arr,int n){
    int k, x = 0;
    for(int i = 0 ;i < n ;n--){
        for(int j = 0;j < n-1; j++){
            if(arr[j]>arr[j+1]){
               k = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = k;
                x++;
            }
        }
        if(x == 0)
        break;
    }
}

int main(){
    int arr[] = {1,2,3,4};
    bubblesort(arr,4);
    for(int i = 0;i<4;i++){
        cout<<arr[i];
    }
return 0;
}