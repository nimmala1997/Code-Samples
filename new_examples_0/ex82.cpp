#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int> &A, int B) {
    int n = A.size();
    sort(A.begin(),A.end());
    int count = 0;
    int le = 1,re = 0;
    for(int i = 0; i < n-1 ; i++){
        int sum = B - A.at(i);
        int s = i +1;
        int e = n -1;
        while( s <= e){
         int mid = s +(e - s)/2; 
         if(A.at(mid) == sum ){
            if(mid == i +1){
                le = mid;
                break;
            }
            else
             if(A.at(mid -1) != sum  ){
               le = mid;
               break;
             }
             else
                e = mid-1;
         }
         if(A.at(mid) > sum)
          e = mid-1;
         if(A.at(mid) < sum)
           s = mid+1;
        }
        s = i + 1;
        e = n - 1;
        while( s <= e){
         int mid = s +(e - s)/2; 
         if(A.at(mid) == sum ){
            if(mid == n -1){
                re = mid;
                break;
            }
            else
             if(A.at(mid + 1) != sum){
              re = mid;
              break;
             }
             else
               s = mid+1;
         }
         if(A.at(mid) > sum)
          e = mid-1;
         if(A.at(mid) < sum)
           s = mid+1;
        }
        count = count + (re-le+1);
        re = 0;
        le = 1;
    }
    return count;
}

int main(){
   int arr[] = {1,2,2,1,3};
   int n = sizeof(arr)/sizeof(arr[0]);
   vector<int> ans(arr,arr+n);
   //vector<int> ans{1,2,2,1,3};
   int a = solve(ans,2);
   cout<<a;
 return 0;
}
