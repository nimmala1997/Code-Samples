#include<iostream>
using namespace std;

void Merge(int arr[], int s, int e ){
    int mid = s + (e-s)/2;
    int temp[100];
    int k = s;
    int i = s,j = mid+1;

   while (i<=mid && j<= e)
   {
     if(arr[i]<=arr[j]){
       temp[k++] = arr[i++];
     }
      else
       temp[k++] = arr[j++];

   }
   while(i <= mid){
         temp[k++] = arr[i++];
      }
   while(j <= e){
         temp[k++] = arr[j++];
      }
   for(int a = s; a <= e; a++){
      arr[a] = temp[a];
   }
   
}

void MergeSort(int arr[], int s, int e){
   if(s >= e)
    return;
    int mid = s + (e-s)/2;
    MergeSort(arr,s,mid);
    MergeSort(arr,mid+1,e);

    Merge(arr,s,e);

}

int main(){
   int n =6;
   //cin>>n;
   int arr[] = {2,5,7,1,3,6};
   /*for(int i = 0; i < n ; i++){
      cin>>arr[i];
   }*/

   MergeSort(arr,0,n-1);
   for(int i = 0 ; i < n ; i++)
    cout<<arr[i];

 return 0;
}