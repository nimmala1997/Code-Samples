#include<iostream>
using namespace std;

int search(int arr[],int n,int x){
        int mid;
        int s = 0;
        int e = n-1;
        mid = (s+e)/2;
        while(mid >= 0 && mid < n ){
            mid = (s+e)/2;
            if(arr[mid] == x)
              return mid;
            if(arr[mid]>x)
              e = mid-1;
            if(arr[mid]<x)
             s = mid+1;
        }
        return -1;
    }
    int firstRepeated(int arr[], int n) {
        // code here
        int temp[n];
        for(int x = 0 ; x < n;x++)
         temp[x] = arr[x];
        sort(temp,temp+n);
        int ans;
        for(int x = 0;x < n;x++){
            ans = search(temp,n,arr[x]);
            //cout<<x<<"k";
            //cout<<ans<<"hello";
            if(ans == 0)
             if(temp[ans+1] == temp[ans])
               return x+1;
            
            if(ans == n-1)
             if(temp[ans] == temp[ans-1])
               return x+1;
            if(ans != 0 && ans != n-1)
            if(temp[ans] == temp[ans-1]||temp[ans] == temp[ans+1]){
             return (x+1);
            }
        }
        return -1;
        
    }

    int main(){
        int arr[] = {1,5,3,4,3,5,6};
        int arr1[] = {0,5,5,9,3,2,8,7,4,8,1,4,3,5,5,2,6,8,9,2,9,5,9};
        //int arr1[] = {1,3,3,4,5,5,6};
        int ans = firstRepeated(arr1,23);
        //int ans = search(arr1,7,3);
        cout<<ans;
        //cout<<ans<<"aa";
    return 0;
    }