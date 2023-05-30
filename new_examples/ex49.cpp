#include<iostream>
#include<vector>

using namespace std;

 vector<int> subarraySum(int arr[], int n, long long s)
    {
        int x = 0;
        int count  = 0;
        vector<int> ans;
        int i = 0;
        while(i <= n ){
            if(count != s){
            if(count < s){
                if(i < n){
                count = count+arr[i];
                i++;
                }
                else
                 return ans;
            }
            else
             if(count > s){
                 count = count-arr[x];
                 x++;
             }
         }
         else{
             ans.push_back(x+1);
             ans.push_back(i);
             return ans;

         }
          
        }
        return ans;
    }

    int main(){
        int n;
        cin>>n;
        int arr[n];
        long long s;
        cin>>s;
        for(int x = 0; x < n;x++){
            cin>>arr[x];
        }
        vector<int> ans = subarraySum(arr,n,s);
        //cout<<ans.size()<<endl;
        for(int x = 0; x < ans.size();x++){
            cout<<ans.at(x)<<" ";
        }
    return 0;
    }