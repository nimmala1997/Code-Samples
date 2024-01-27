#include<iostream>
#include<vector>
using namespace std;

vector<int> beauty(int* arr,int n){
     int ev0 = 0,odd0 = 0,ev = 0,odd = 0;
     vector<int> ans;

     for(int i = 0; i < n; i++){
      if(i%2 == 0)
        ev += arr[i];
        else 
         odd += arr[i];
     }
     for(int i = 0 ; i < n; i++){
      if(i == 0){
         ev -= arr[i];
      }
      else{
         if(i%2 != 0){
            odd -= arr[i];
            ev0 += arr[i-1];
         }
         else {
             ev -= arr[i];
             odd0 += arr[i-1];
         }
      }
      if(ev+odd0 == odd+ev0)
       ans.push_back(i);
     }
     return ans;
}

int main(){
   int n;
   int arr[] = {4,3,2,7,6,-2};
   vector<int> ans = beauty(arr,6);

    for(int i = 0; i < ans.size(); i++){
      cout<<ans.at(i);
    }

 return 0;
}