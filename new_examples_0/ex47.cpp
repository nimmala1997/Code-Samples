#include<iostream>
#include<vector>

using namespace std;

vector<int> mergevec(vector<int>arr1,vector<int>arr2){
        int x = 0 ;
        int y = 0 ;
        vector<int>arr;
        while(x < arr1.size() && y < arr2.size()){
            if(arr1.at(x)<=arr2.at(y)){
                arr.push_back(arr1[x]);
                x++;
            }
            else
            if(arr1.at(x)>arr2.at(y)){
                arr.push_back(arr2[y]);
                y++;
            }
        }
        if(x == arr1.size()){
            while(y < arr2.size()){
                arr.push_back(arr2[y]);
                y++;
            }
        }
        else
         if(y == arr2.size()){
            while(x < arr1.size()){
                arr.push_back(arr1[x]);
                x++;
            }
         }
    return arr;
        
    }
    vector<int> sortArr(vector<int>arr, int n){
    if(n == 0 || n == 1)
     return arr;
    vector<int> arr1,arr2,arr5;
    int mid = (n-1)/2;
    for(int x = 0 ; x <= mid;x++)
      arr1.push_back(arr[x]);
    for(int x = mid+1; x < n;x++ )
      arr2.push_back(arr[x]);
    arr1 = sortArr(arr1,arr1.size());
    arr2 = sortArr(arr2,arr2.size());
    arr5 = mergevec(arr1,arr2);
    return arr5;
    }
int main(){
    int n;
    cin>>n;
    vector<int> arr1;
    int x ;
    for(int a = 0; a < n; a++){
        cin>>x;
        arr1.push_back(x);
    }
    vector<int> ans = sortArr(arr1,n);
    //cout<<ans[0];
    
    for(int a = 0; a < ans.size(); a++){
       cout<<ans[a];
    }

return 0;

}