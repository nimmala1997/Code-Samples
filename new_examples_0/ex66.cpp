#include<iostream>
using namespace std;

int pivotsort(int arr[],int s,int e){
    int i = s,j;
    for(j = s;j < e;j++ ){
        if(arr[j]<arr[e]){
          swap(arr[i],arr[j]);
         i++;
        }
    }
    swap(arr[i],arr[e]);
    return i;
}

void quicksort(int arr[],int s,int e){
    if(s >= e)
     return;
    int p = pivotsort(arr,s,e);

    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}

int main(){
    int arr[] = {5,3,1,6,2,4};
    quicksort(arr,0,5);
    for (int i = 0; i < 6; i++)
    {
      cout<<arr[i];
    }
    

    
}